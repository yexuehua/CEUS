

#include "USToolKitActivor.h"
#include "USToolKitView.h"


#include <QMessageBox>
#include <iostream>
#include "DealLicense.h"
#include "DealRegistry.h"

namespace mitk
{
  void USToolKitActivor::start(ctkPluginContext *context)
  {
//	  DealLicense deallicence;
//	  if (deallicence.checkAuthorization("PM"))
//	  {
			BERRY_REGISTER_EXTENSION_CLASS(USToolKitView, context)
//	  }
//	  else
//	  {
//			QMessageBox::information(NULL, "License", "Your license maybe invalid!");
//		exit(-1);
//  }
  }

  void USToolKitActivor::stop(ctkPluginContext *context) { Q_UNUSED(context) }




}
