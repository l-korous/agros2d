// This file is part of Agros2D.
//
// Agros2D is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Agros2D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Agros2D.  If not, see <http://www.gnu.org/licenses/>.
//
// hp-FEM group (http://hpfem.org/)
// University of Nevada, Reno (UNR) and University of West Bohemia, Pilsen
// Email: agros2d@googlegroups.com, home page: http://hpfem.org/agros2d/

#include "util.h"
#include "scene.h"
#include "scenenode.h"
#include "scenemarker.h"
#include "scenemarkerdialog.h"


SceneNode::SceneNode(const Point &point) : SceneBasic()
{
    logMessage("SceneNode::SceneNode()");

    this->point = point;
}

double SceneNode::distance(const Point &point) const
{
    logMessage("SceneNode::distance()");

    return (this->point - point).magnitude();
}

int SceneNode::showDialog(QWidget *parent, bool isNew)
{
    logMessage("SceneNode::showDialog()");

    DSceneNode *dialog = new DSceneNode(this, parent, isNew);
    return dialog->exec();
}

SceneNodeCommandRemove* SceneNode::getRemoveCommand()
{
    return new SceneNodeCommandRemove(this->point);
}


// *************************************************************************************************************************************

SceneNode* SceneNodeContainer::get(SceneNode *node) const
{
    foreach (SceneNode *nodeCheck, data)
    {
        if (nodeCheck->point == node->point)
        {
            return nodeCheck;
        }
    }

    return NULL;
}

SceneNode* SceneNodeContainer::get(const Point &point) const
{
    foreach (SceneNode *nodeCheck, data)
    {
        if (nodeCheck->point == point)
            return nodeCheck;
    }

    return NULL;
}

RectPoint SceneNodeContainer::boundingBox() const
{
    Point min( numeric_limits<double>::max(),  numeric_limits<double>::max());
    Point max(-numeric_limits<double>::max(), -numeric_limits<double>::max());

    foreach (SceneNode *node, data)
    {
        min.x = qMin(min.x, node->point.x);
        max.x = qMax(max.x, node->point.x);
        min.y = qMin(min.y, node->point.y);
        max.y = qMax(max.y, node->point.y);
    }

    return RectPoint(min, max);
}

SceneNodeContainer SceneNodeContainer::selected()
{
    SceneNodeContainer list;
    foreach (SceneNode* item, this->data)
    {
        if (item->isSelected)
            list.data.push_back(item);
    }

    return list;
}


// *************************************************************************************************************************************

DSceneNode::DSceneNode(SceneNode *node, QWidget *parent, bool isNew) : DSceneBasic(parent, isNew)
{
    logMessage("DSceneNode::DSceneNode()");

    m_object = node;

    setWindowIcon(icon("scene-node"));
    setWindowTitle(tr("Node"));

    createControls();

    load();

    setMinimumSize(sizeHint());
    // setMaximumSize(sizeHint());
}

DSceneNode::~DSceneNode()
{
    logMessage("DSceneNode::~DSceneNode()");

    delete txtPointX;
    delete txtPointY;
}

QLayout* DSceneNode::createContent()
{
    logMessage("DSceneNode::createContent()");

    txtPointX = new ValueLineEdit();
    txtPointY = new ValueLineEdit();
    connect(txtPointX, SIGNAL(editingFinished()), this, SLOT(doEditingFinished()));
    connect(txtPointY, SIGNAL(editingFinished()), this, SLOT(doEditingFinished()));
    connect(txtPointX, SIGNAL(evaluated(bool)), this, SLOT(evaluated(bool)));
    connect(txtPointY, SIGNAL(evaluated(bool)), this, SLOT(evaluated(bool)));
    lblDistance = new QLabel();
    lblAngle = new QLabel();

    // coordinates must be greater then or equal to 0 (axisymmetric case)
    if (Util::scene()->problemInfo()->coordinateType == CoordinateType_Axisymmetric)
        txtPointX->setMinimum(0.0);

    QFormLayout *layout = new QFormLayout();
    layout->addRow(Util::scene()->problemInfo()->labelX() + " (m):", txtPointX);
    layout->addRow(Util::scene()->problemInfo()->labelY() + " (m):", txtPointY);
    layout->addRow(tr("Distance:"), lblDistance);
    layout->addRow(tr("Angle:"), lblAngle);

    return layout;
}

bool DSceneNode::load()
{
    logMessage("DSceneNode::load()");

    SceneNode *sceneNode = dynamic_cast<SceneNode *>(m_object);

    txtPointX->setNumber(sceneNode->point.x);
    txtPointY->setNumber(sceneNode->point.y);

    doEditingFinished();

    return true;
}

bool DSceneNode::save()
{
    logMessage("DSceneNode::save()");

    if (!txtPointX->evaluate(false)) return false;
    if (!txtPointY->evaluate(false)) return false;

    SceneNode *sceneNode = dynamic_cast<SceneNode *>(m_object);

    Point point(txtPointX->number(), txtPointY->number());

    // check if node doesn't exists
    if (Util::scene()->getNode(point) && ((sceneNode->point != point) || isNew))
    {
        QMessageBox::warning(this, tr("Node"), tr("Node already exists."));
        return false;
    }

    if (!isNew)
    {
        if (sceneNode->point != point)
        {
            Util::scene()->undoStack()->push(new SceneNodeCommandEdit(sceneNode->point, point));
        }
    }

    sceneNode->point = point;

    return true;
}

void DSceneNode::doEditingFinished()
{
    logMessage("DSceneNode::doEditingFinished()");

    lblDistance->setText(QString("%1 m").arg(sqrt(Hermes::sqr(txtPointX->number()) + Hermes::sqr(txtPointY->number()))));
    lblAngle->setText(QString("%1 deg.").arg(
            (sqrt(Hermes::sqr(txtPointX->number()) + Hermes::sqr(txtPointY->number())) > EPS_ZERO)
            ? atan2(txtPointY->number(), txtPointX->number()) / M_PI * 180.0 : 0.0));
}


// undo framework *******************************************************************************************************************

SceneNodeCommandAdd::SceneNodeCommandAdd(const Point &point, QUndoCommand *parent) : QUndoCommand(parent)
{
    logMessage("SceneNodeCommandAdd::SceneNodeCommandAdd()");

    m_point = point;
}

void SceneNodeCommandAdd::undo()
{
    logMessage("SceneNodeCommandAdd::undo()");

    SceneNode *node = Util::scene()->getNode(m_point);
    if (node)
    {
        Util::scene()->nodes->remove(node);
    }
}

void SceneNodeCommandAdd::redo()
{
    logMessage("SceneNodeCommandAdd::redo()");

    Util::scene()->addNode(new SceneNode(m_point));
}

SceneNodeCommandRemove::SceneNodeCommandRemove(const Point &point, QUndoCommand *parent) : QUndoCommand(parent)
{
    logMessage("SceneNodeCommandRemove::SceneNodeCommandRemove()");

    m_point = point;
}

void SceneNodeCommandRemove::undo()
{
    logMessage("SceneNodeCommandRemove::undo()");

    Util::scene()->addNode(new SceneNode(m_point));
}

void SceneNodeCommandRemove::redo()
{
    logMessage("SceneNodeCommandRemove::redo()");

    SceneNode *node = Util::scene()->getNode(m_point);
    if (node)
    {
        Util::scene()->nodes->remove(node);
    }
}

SceneNodeCommandEdit::SceneNodeCommandEdit(const Point &point, const Point &pointNew, QUndoCommand *parent) : QUndoCommand(parent)
{
    logMessage("SceneNodeCommandEdit::SceneNodeCommandEdit()");

    m_point = point;
    m_pointNew = pointNew;
}

void SceneNodeCommandEdit::undo()
{
    logMessage("SceneNodeCommandEdit::undo()");

    SceneNode *node = Util::scene()->getNode(m_pointNew);
    if (node)
    {
        node->point = m_point;
        Util::scene()->refresh();
    }
}

void SceneNodeCommandEdit::redo()
{
    logMessage("SceneNodeCommandEdit:redo:()");

    SceneNode *node = Util::scene()->getNode(m_point);
    if (node)
    {
        node->point = m_pointNew;
        Util::scene()->refresh();
    }
}

