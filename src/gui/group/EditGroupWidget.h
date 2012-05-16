/*
 *  Copyright (C) 2011 Felix Geyer <debfx@fobos.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_EDITGROUPWIDGET_H
#define KEEPASSX_EDITGROUPWIDGET_H

#include <QtCore/QScopedPointer>

#include "gui/EditWidget.h"
#include "core/Group.h"

class EditWidgetIcons;

namespace Ui {
    class EditGroupWidgetMain;
    class EditWidget;
}

class EditGroupWidget : public EditWidget
{
    Q_OBJECT

public:
    explicit EditGroupWidget(QWidget* parent = 0);
    ~EditGroupWidget();

    void loadGroup(Group* group, bool create, Database* database);

Q_SIGNALS:
    void editFinished(bool accepted);

private Q_SLOTS:
    void save();
    void cancel();

private:
    const QScopedPointer<Ui::EditGroupWidgetMain> m_mainUi;
    QWidget* const m_editGroupWidgetMain;
    EditWidgetIcons* const m_editGroupWidgetIcons;
    Group* m_group;
    Database* m_database;

    Q_DISABLE_COPY(EditGroupWidget)
};

#endif // KEEPASSX_EDITGROUPWIDGET_H