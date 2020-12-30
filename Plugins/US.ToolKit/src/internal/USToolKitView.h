
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
#include <mpfit.h>

// GammaFitting
struct vars_struct
{
	double    *n;                //phase number
	float    *t;                //phase time
	double    *value;                //concentration value
	double    at;                //initial bolus arrival time
	double    *ey;            //weight for each point
	double    *originalAif;
	double    delay;            //time delay
	int        lastTime;        //last time
};

// bolus plot parameters
struct CBParam
{
	double PE;        //Peak Enhancement 
	double WiAUC;     //Wash-in Area Under the Curve ( AUC (TI:TTP) ) 
	double RT;        //Rise Time ( TTP – TI ) 
	double mTTI;      //mean Transit Time local ( mTT – TI ) 

	double TTP;       //Time To Peak 

	double WiR;		  //Wash-in Rate ( maximum slope ) 

	double WiPI;      //Wash-in Perfusion Index ( WiAUC / RT ) 

	double WoAUC;     //Wash-out AUC ( AUC (TTP:TO) ) 

	double WiWoAUC;   //Wash-in and Wash-out AUC ( WiAUC + WoAUC ) 

	double FT;        //Fall Time ( TO – TTP ) 

	double WoR;       //Wash-out Rate ( minimum slope ) 

	double QOF;       //Quality Of Fit between the echo-power signal and f(t) 

};

//replenishment plot parameters
struct CRParam
{
	double rBV;
	double WiR;
	double mTT;
	double PI;
	double QOF;
};

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
	//void USPreprocessDataSelection(int index);
	void USReferenceDataSelection(int index);
	void USLesionDataSelection(int index);
	void USRGBConvertGray();
	void USConvertToEchoPower();
	void USDenoiseStart();
	void USSequenceEdit(int index);
	void DCEUSDynamicDisply();
	void DCEUSStaticDisply();
	void ColorUSDisply();
	void USQuantitation();

private:
	//data loading
	QVector<QString> multiUSFileName;
	QVector<QString> multiUSDataPath;
	QVector<QString> multiUSDataName;

	template<typename TImageType>
	mitk::Image::Pointer ReadRGBImageFileByITK(const std::string filename);
	void GlobalReinit(bool);
	void ShowOnlySelectedNodes(const mitk::DataNode* selectedNode);
	void ReadImageFromFolder(const QString & path);
	void USExtractROI();
	void USGetTimeData(mitk::DataNode *dataNode, double *tempGrid);
	void USCurveTIC(std::vector<double> tempGrid, std::vector<double> statisticsMean, std::vector<double> fit);
	void USModelFit(int timeSteps, double *t, double *y, double *fit);
	void USCalculateParam(std::vector<double> timeGrid, std::vector<double> fit, CBParam *BP);
	void USShowParamTable(CBParam *BP);

};
#endif 
