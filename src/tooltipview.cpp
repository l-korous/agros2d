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

#include "tooltipview.h"

TooltipView::TooltipView(QWidget *parent): QDockWidget(tr("Hints"), parent)
{
    setMinimumSize(160, 160);
    setObjectName("TooltipView");

    webView = new QWebView(this);
    webView->settings()->setAttribute(QWebSettings::PluginsEnabled, false);
    webView->settings()->setAttribute(QWebSettings::JavaEnabled, false);
    webView->setAcceptDrops(false);

    setWidget(webView);
}

void TooltipView::loadTooltip(const QString &html)
{
    webView->setHtml(html);
}

void TooltipView::loadTooltip(SceneMode sceneMode)
{
    switch (sceneMode)
    {
    case SceneMode_OperateOnNodes:
        loadTooltip(tr("Tooltip_OperateOnNodes"));
        break;
    case SceneMode_OperateOnEdges:
        loadTooltip(tr("Tooltip_OperateOnEdges"));
        break;
    case SceneMode_OperateOnLabels:
        loadTooltip(tr("Tooltip_OperateOnLabels"));
        break;
    case SceneMode_Postprocessor:
        loadTooltip(tr("Tooltip_Postprocessor"));
        break;
    }
}
