/*
    Copyright (C) 2010 UFO Coders <info@ufocoders.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "sendfilewizard.h"
#include "obexagent.h"
#include "pages/selectfilespage.h"
#include "pages/selectdevicepage.h"
#include "pages/connectingpage.h"
#include "pages/sendintropage.h"

#include <QApplication>

#include <kstandardguiitem.h>
#include <klocalizedstring.h>
#include <kpushbutton.h>
#include "kfilewidget.h"

#include <bluedevil/bluedevil.h>

using namespace BlueDevil;

SendFileWizard::SendFileWizard() : QWizard(), m_device(0)
{
    setWindowTitle(i18n("BlueDevil Send Files"));

    setButton(QWizard::BackButton, new KPushButton(KStandardGuiItem::back(KStandardGuiItem::UseRTL)));
    setButton(QWizard::NextButton, new KPushButton(KStandardGuiItem::forward(KStandardGuiItem::UseRTL)));
    setButton(QWizard::CancelButton, new KPushButton(KStandardGuiItem::cancel()));

    //We do not want "Forward" as text
    setButtonText(QWizard::NextButton, i18n("Next"));

    addPage(new SendIntroPage());
    addPage(new SelectFilesPage());
    addPage(new SelectDevicePage());
    addPage(new ConnectingPage());

    show();

    ObexAgent *agent = new ObexAgent(qApp);
}

SendFileWizard::~SendFileWizard()
{

}

void SendFileWizard::setFileWidget(KFileWidget* fileWidget)
{
    m_fileWidget = fileWidget;
}

KFileWidget* SendFileWizard::fileWidget()
{
    return m_fileWidget;
}

void SendFileWizard::setDevice(Device* device)
{
    m_device = device;
}

Device* SendFileWizard::device()
{
    return m_device;
}
