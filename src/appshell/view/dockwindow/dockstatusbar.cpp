//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2020 MuseScore BVBA and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================
#include "dockstatusbar.h"

#include <QWidget>

using namespace mu::dock;

DockStatusBar::DockStatusBar(QQuickItem* parent)
    : DockView(parent)
{
    setHeight(40);

    connect(this, &DockPanel::visibleChanged, this, [this]() {
        if (view()) {
            view()->setVisible(isVisible());
        }

        emit visibleChanged(isVisible());
    });
}

DockStatusBar::~DockStatusBar()
{
}

DockStatusBar::Widget DockStatusBar::widget() const
{
    return m_widget;
}

void DockStatusBar::onComponentCompleted()
{
    m_widget.widget = view();
    m_widget.widget->setFixedHeight(height());
}
