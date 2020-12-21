
#ifndef USToolKitView_h
#define USToolKitView_h

//berry
#include <berryISelectionListener.h>
#include <berryISelectionService.h>
#include <berryIWorkbenchWindow.h>
#include <berryPlatform.h>
#include <berryIPreferences.h>
#include <berryIPreferencesService.h>
#include <berryIBerryPreferences.h>
#include "usServiceRegistration.h"

//qt
#include <QSettings>
#include <QFileDialog>
#include <QDir>
#include <QProgressDialog>
#include <QList>

//qmitk
#include "QmitkStdMultiWidget.h"
#include <QmitkAbstractView.h>
#include "QmitkRegisterClasses.h"

//mitk
#include "mitkIRenderWindowPart.h"
#include "mitkNodePredicateAnd.h"
#include "mitkNodePredicateOr.h"
#include "mitkNodePredicateNot.h"
#include <mitkNodePredicateProperty.h>
#include "mitkImage.h"
#include <mitkBoundingShapeInteractor.h>
#include <mitkDataStorage.h>
#include <mitkEventConfig.h>
#include <mitkGeometryData.h>
#include <mitkPointSet.h>
#include <mitkWeakPointer.h>
#include "mitkPointSetDataInteractor.h"
#include "mitkBoundingObject.h"

//itk
#include "itkImageIOBase.h"
#include "itkCommand.h"
#include <itkImage.h>
#include <itksys/SystemTools.hxx>

//vtk
#include <vtkEventQtSlotConnect.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>

//ui
#include "ui_USToolKitViewControls.h"

//stl
#include <string>

//PK Modeling
#include "mitkModelBase.h"
#include "QmitkParameterFitBackgroundJob.h"
#include "mitkModelFitResultHelper.h"
#include "mitkModelFactoryBase.h"
#include "mitkLevenbergMarquardtModelFitFunctor.h"
#include "mitkSimpleBarrierConstraintChecker.h"
#include "mitkAIFBasedModelBase.h"


#include "QmitkStepperAdapter.h"
#include <mitkDataStorageSelection.h>


class USToolKitView : public QmitkAbstractView 
{
  Q_OBJECT

public:
	static const std::string VIEW_ID;
	USToolKitView(QObject *parent = 0);
	virtual ~USToolKitView();


protected:
	virtual void CreateQtPartControl(QWidget *parent) override;
	virtual void SetFocus() override;
	virtual void OnSelectionChanged(berry::IWorkbenchPart::Pointer source,
                                  const QList<mitk::DataNode::Pointer> &nodes) override;
  
								  
	Ui::USToolKitViewControls m_Controls;
	const QString m_DEFAULT_DIR_KEY;


protected slots:
	
	//data loading
	void LoadDicomUS();
	void USQuantitation();
	//void USPreprocessDataSelection(int index);
	void USReferenceDataSelection(int index);
	void USRGBConvertGray();
	//void USExtractChannel();

private:
	//data loading
	QVector<QString> multiUSFileName;
	QVector<QString> multiUSDataPath;
	QVector<QString> multiUSDataName;

	template<typename TImageType>
	mitk::Image::Pointer ReadRGBImageFileByITK(const std::string filename);

	void ConvertToEchoPower();
	void GlobalReinit(bool);
	void ShowOnlySelectedNodes(const mitk::DataNode* selectedNode);
	void ReadImageFromFolder(const QString & path);
	bool ShowSUVInfo(std::string USDicomPath);

};
#endif 
