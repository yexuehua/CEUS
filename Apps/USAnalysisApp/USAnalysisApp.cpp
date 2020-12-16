

#include <mitkBaseApplication.h>

#include <QVariant>

int main(int argc, char **argv)
{
  // Create a QApplication instance first
  mitk::BaseApplication myApp(argc, argv);
  myApp.setApplicationName("USAnalysisApp");
  myApp.setOrganizationName("DKFZ");

  //QStringList preloadLibs;
  //preloadLibs << "liborg_mitk_gui_qt_ext";
  //myApp.setPreloadLibraries(preloadLibs);

  myApp.setProperty(mitk::BaseApplication::PROP_APPLICATION, "org.mitk.qt.extapplication");
  return myApp.run();
}
