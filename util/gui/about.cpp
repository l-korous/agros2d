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

#include "about.h"

#include "../util.h"
#include "../util/checkversion.h"
#include "../util/system_utils.h"

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent)
{
    setWindowModality(Qt::ApplicationModal);
    setModal(true);

    setWindowIcon(icon("agros2d"));
    setWindowTitle(tr("About..."));

    createControls();

    setMinimumSize(450, 550);
    setMaximumSize(sizeHint());
}

AboutDialog::~AboutDialog()
{

}

void AboutDialog::createControls()
{
    QTabWidget *tab = new QTabWidget();
    tab->addTab(createAgros2D(), icon(""), tr("Agros2D"));
    tab->addTab(createHermes2D(), tr("Hermes2D"));
    tab->addTab(createLibraries(), tr("Libraries"));
    tab->addTab(createLicense(), tr("License"));
    tab->addTab(createSysinfo(), tr("System Informations"));

    QPushButton *buttonClose = new QPushButton(tr("Close"));
    QPushButton *buttonCheckForNewVersion = new QPushButton(tr("Check version"));

    QHBoxLayout *buttonBox = new QHBoxLayout();
    buttonBox->addStretch();
    buttonBox->addWidget(buttonCheckForNewVersion);
    buttonBox->addWidget(buttonClose);

    connect(buttonClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonCheckForNewVersion, SIGNAL(clicked()), this, SLOT(checkVersion()));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tab);
    // layout->addStretch();
    layout->addLayout(buttonBox);

    setLayout(layout);
}

QWidget *AboutDialog::createAgros2D()
{
    QLabel *labelContent = new QLabel(tr("<h3>Agros2D %1</h3>"
                                         "Agros2D is a multiplatform multiphysics application for the solution of partial differential equations (PDE) "
                                         "based on the <a href=\"http://hpfem.org/hermes2d/\">Hermes2D</a> library using higher order finite element method "
                                         "(<i>hp</i>-FEM) with automatic adaptivity.<br/><br/>"
                                         "Web page: <a href=\"http://agros2d.org/\">http://agros2d.org/</a><br/>"
                                         "Facebook: <a href=\"http://www.facebook.com/pages/Agros2D/132524130149770?sk=info\">http://www.facebook.com/pages/Agros2D/...</a><br/>"
                                         "Issues: <a href=\"http://github.com/hpfem/agros2d/issues\">http://github.com/hpfem/agros2d/issues</a><br/><br/>"
                                         "<b>Authors:</b>"
                                         "<p>"
                                         "<b>Pavel Karban</b> - main developer (University of West Bohemia, Pilsen)<br/>"
                                         "<b>František Mach</b> - developer, Python script (University of West Bohemia, Pilsen)<br/>"
                                         "<b>Pavel Kůs</b> - developer, coupled problems, time domain adaptivity (University of West Bohemia, Pilsen)<br/>"
                                         "<b>David Pánek</b> - developer (University of West Bohemia, Pilsen)<br/>"
                                         "<b>Lukáš Korous</b> - developer (University of West Bohemia, Pilsen)<br/>"
                                         "<b>Lukáš Koudela</b> - developer - RF module (University of West Bohemia, Pilsen)<br/>"
                                         "<b>Bartosz Sawicki</b> - Polish translation (Warsaw University of Technology, Warsaw)<br/>"
                                         "<b>Václav Kotlan</b> - German translation (University of West Bohemia, Pilsen)<br/>"
                                         "<b>Petr Kropík</b> - University of West Bohemia, Pilsen<br/>"
                                         "<b>Denys Nikolayev</b> - Russion and French translation, University of West Bohemia, Pilsen<br/>"
                                         "</p>")
                                      .arg(QApplication::applicationVersion()));
    labelContent->setWordWrap(true);
    labelContent->setOpenExternalLinks(true);


    QLabel *labelIcon = new QLabel();
    labelIcon->setPixmap(icon("agros2d").pixmap(64, 64));

    QGridLayout *layoutIcon = new QGridLayout();
    layoutIcon->addWidget(labelIcon, 0, 0, 1, 1, Qt::AlignTop);
    layoutIcon->addWidget(labelContent, 0, 1);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(layoutIcon);
    layout->addStretch();

    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    return widget;
}

QWidget *AboutDialog::createHermes2D()
{
    QLabel *labelContent = new QLabel(tr("<h3>Hermes2D</h3>"
                                         "Web page: <a href=\"http://hpfem.org/hermes/\">http://hpfem.org/hermes/</a><br/><br/>"
                                         "<b>Authors:</b>"
                                         "<p>"
                                         "<b>Pavel Solin</b> (project leader, University of Nevada, Reno)<br/>"
                                         "<b>Martin Zitka</b> (formerly University of Texas at El Paso)<br/>"
                                         "<b>Tomas Vejchodsky</b> (Academy of Sciences of the Czech Republic, Prague)<br/>"
                                         "<b>Svatava Vyvialova</b> (formerly University of Texas at El Paso)<br/>"
                                         "<b>Jakub Cerveny</b> (formerly University of Texas at El Paso)<br/>"
                                         "<b>Lenka Dubcova</b> (Academy of Sciences of the Czech Republic, Prague)<br/>"
                                         "<b>Ondrej Certik</b> (University of Nevada, Reno)<br/>"
                                         "<b>Robert Cimrman</b> (New Technologies Research Centre, Pilsen)<br/>"
                                         "<b>Ivo Hanak</b> (University of West Bohemia, Pilsen)<br/>"
                                         "<b>David Andrs</b> (formerly University of Nevada, Reno)<br/>"
                                         "<b>Pavel Karban</b> (University of West Bohemia, Pilsen)<br/>"
                                         "<b>Frantisek Mach</b> (University of West Bohemia, Pilsen)<br/>"
                                         "<b>Sameer Regmi</b> (University of Nevada, Reno)<br/>"
                                         "<b>David Puga</b>l (University of Nevada, Reno)<br/>"
                                         "<b>Ma Zhonghua</b> (China University of Petroleum, Beijing)<br/>"
                                         "<b>Milan Hanus</b> (University of West Bohemia, Pilsen)<br/>"
                                         "<b>Damien Lebrun-Grandie</b> (Texas A&M University)<br/>"
                                         "<b>Lukas Korous</b> (Charles University, Prague)<br/>"
                                         "<b>Valmor de Almeida</b> (Oak Ridge National Laboratory, Oak Ridge)<br/>"
                                         "</p>"
                                         ));
    labelContent->setWordWrap(true);
    labelContent->setOpenExternalLinks(true);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(labelContent);
    layout->addStretch();

    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    return widget;
}

QWidget *AboutDialog::createLibraries()
{
    QLabel *labelContent = new QLabel(tr("<h3>Libraries</h3>"
                                         "<b>Digia Qt:</b> Digia Qt (<a href=\"http://qt.digia.com/\">Qt - Cross-platform application and UI development framework</a>)<br/>"
                                         "<b>QCustomChart:</b> QCustomChart (<a href=\"http://www.workslikeclockwork.com/index.php/components/qt-plotting-widget/\">Qt Plotting Widget</a>)<br/>"
                                         "<b>Python:</b> Python Programming Language (<a href=\"http://www.python.org\">Python</a>)<br/>"
                                         "<b>libdxfrw:</b> LibreCAD DXF library (<a href=\"http://sourceforge.net/projects/libdxfrw/\">libdxfrw</a>)<br/>"
                                         "<b>ctemplate:</b> Simple but powerful template language for C++ (<a href=\"http://code.google.com/p/ctemplate/\">ctemplate</a>)<br/>"
                                         "<b>BSON:</b> BSON implementation (<a href=\"https://github.com/mongodb/mongo-c-driver/\">mongo-c-driver</a>)<br/>"
                                         "<b>matio:</b> MAT File I/O Library (<a href=\"http://sourceforge.net/projects/matio/\">matio</a>)<br/>"
                                         "<b>poly2tri:</b> A 2D constrained Delaunay triangulation library (<a href=\"http://code.google.com/p/poly2tri/\">poly2tri</a>)<br/>"
                                         "<b>stb_truetype.h:</b> TrueType processing library - Sean Barrett / RAD Game Tools (<a href=\"http://nothings.org/\">stb</a>)<br/>"
                                         "<b>Triangle:</b> Jonathan Richard Shewchuk (<a href=\"http://www.cs.cmu.edu/~quake/triangle.html\">Triangle</a>)<br/>"
                                         "<b>Gmsh:</b> A three-dimensional finite element mesh generator (<a href=\"http://geuz.org/gmsh\">Gmsh</a>)<br/>"
                                         "<b>UMFPACK:</b> unsymmetric multifrontal sparse LU factorization package (<a href=\"http://www.cise.ufl.edu/research/sparse/umfpack/\">UMFPACK</a>)<br/>"
                                         "<b>MUMPS:</b> A MUltifrontal Massively Parallel sparse direct Solver (<a href=\"http://graal.ens-lyon.fr/MUMPS/\">MUMPS</a>)<br/>"
                                         "<b>SuperLU:</b> Direct solver for large sparse systems of linear equations (<a href=\"http://crd-legacy.lbl.gov/~xiaoye/SuperLU/\">SuperLU</a>)<br/>"
                                         "<b>PARALUTION:</b> Sparse iterative solvers on multi-core CPU and GPU devices (<a href=\"http://www.paralution.com/\">PARALUTION</a>)<br/>"
                                         ));
    labelContent->setWordWrap(true);
    labelContent->setOpenExternalLinks(true);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(labelContent);
    layout->addStretch();

    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    return widget;
}

QWidget *AboutDialog::createLicense()
{
    QLabel *labelContent = new QLabel(tr("<h3>License:</h3>"
                                         "<p>Agros2D is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version.</p><p>Agros2D is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.</p><p>You should have received a copy of the GNU General Public License along with Agros2D. If not, see <a href=\"http://www.gnu.org/licenses/\">http://www.gnu.org/licenses/</a>."
                                         ));
    labelContent->setWordWrap(true);
    labelContent->setOpenExternalLinks(true);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(labelContent);
    layout->addStretch();

    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    return widget;
}

QWidget *AboutDialog::createSysinfo()
{
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(new QLabel(tr("OS:")), 0, 0);
    layout->addWidget(new QLabel(SystemUtils::operatingSystem()), 0, 1);
    layout->addWidget(new QLabel(""), 9, 0);
    layout->addWidget(new QLabel(tr("Processor:")), 10, 0);
    layout->addWidget(new QLabel(SystemUtils::cpuType()), 10, 1);
    layout->addWidget(new QLabel(tr("Number of threads:")), 11, 0);
    layout->addWidget(new QLabel(QString::number(SystemUtils::numberOfThreads())), 11, 1);
    layout->addWidget(new QLabel(tr("Memory:")), 12, 0);
    layout->addWidget(new QLabel(QString("%1 MB").arg(SystemUtils::totalMemorySize() / 1024 / 1024)), 12, 1);
    layout->addWidget(new QLabel(tr("Screen resolution:")), 13, 0);
    layout->addWidget(new QLabel(QString("%1 x %2").
                                 arg(QApplication::desktop()->screenGeometry().width()).
                                 arg(QApplication::desktop()->screenGeometry().height())), 13, 1);
    layout->setRowStretch(20, 1);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    return widget;
}

void AboutDialog::checkVersion()
{
    checkForNewVersion();
}
