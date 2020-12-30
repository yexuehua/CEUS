
// Blueberry
#include <berryISelectionService.h>
#include <berryIWorkbenchWindow.h>
#include <berryPlatform.h> 

//ctk
#include <ctkPluginContext.h>

//us
#include "usModuleResource.h"
#include "usModuleResourceStream.h"
#include <usModuleRegistry.h>
#include <usGetModuleContext.h>

//stl
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <math.h>

// QT
#include <qlabel.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qradiobutton.h>
#include <QSettings>
#include <QFileDialog>
#include <QString>
#include <QProcess>
#include <QAction>
#include <QCheckBox>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QSpinBox>
#include <QSlider>
#include <QApplication>
#include "qobject.h"

//qmitk
#include "QmitkStdMultiWidget.h"
#include "QmitkDataNodeSelectionProvider.h"
#include "QmitkSliceBasedInterpolatorWidget.h"
#include "QmitkSlicesInterpolator.h"
#include <QmitkIOUtil.h>

//mitk
#include "mitkDataNodeObject.h"
#include "mitkIRenderWindowPart.h"
#include "mitkIRenderingManager.h"
#include "mitkStatusBar.h"
#include "mitkTransferFunctionProperty.h"
#include "mitkProgressBar.h"
#include "mitkContour.h"
#include "mitkVtkPropRenderer.h"
#include <mitkBoundingShapeInteractor.h>
#include <mitkBoundingShapeCropper.h>
#include <mitkDisplayInteractor.h>
#include <mitkIDataStorageService.h>
#include <mitkImageAccessByItk.h>
#include <mitkImageStatisticsHolder.h>
#include <mitkInteractionConst.h>
#include <mitkNodePredicateNot.h>
#include <mitkNodePredicateProperty.h>
#include <mitkNodePredicateFunction.h>
#include <mitkMaskImageFilter.h>
#include <mitkSurfaceToImageFilter.h>
#include "mitkVtkResliceInterpolationProperty.h"
#include "mitkSegmentationObjectFactory.h"
#include "mitkProgressBar.h"
#include "mitkNodePredicateDataType.h"
#include "mitkNodePredicateDimension.h"
#include "mitkNodePredicateAnd.h"
#include "mitkNodePredicateOr.h"
#include "mitkImageTimeSelector.h"
#include "mitkProperties.h"
#include <mitkIOUtil.h>
#include <mitkStandaloneDataStorage.h>
#include <mitkILinkedRenderWindowPart.h>
#include "mitkCameraController.h"
#include "mitkApplicationCursor.h"
#include "mitkSurfaceInterpolationController.h"
#include "mitkImageToSurfaceFilter.h"
#include <mitkMorphologicalOperations.h>
#include <mitkBooleanOperation.h>
#include "mitkLookupTableProperty.h"
#include "mitkRenderingModeProperty.h"
#include "mitkIgnorePixelMaskGenerator.h"
#include "mitkLabelSetImage.h"
#include "mitkRenderingManager.h"
#include "mitkSegTool2D.h"
#include "mitkImageCast.h"
#include "mitkITKImageImport.h"
#include "mitkImageStatisticsCalculator.h"
#include "mitkImageMaskGenerator.h"
#include "mitkToolManagerProvider.h"
#include "mitkArbitraryTimeGeometry.h"
#include "mitkMaskedDynamicImageStatisticsGenerator.h"
#include "mitkDICOMQIPropertyHelper.h"
#include "mitkPatlakModelParameterizer.h"
#include "mitkPatlakModelFactory.h"
//#include "mitkImageToOpenCVImageFilter.h"
//#include "mitkConvertGrayscaleOpenCVImageFilter.h"
//#include "mitkOpenCVToMitkImageFilter.h"

// ITK 
#include <itkVectorImage.h>
#include <itkNiftiImageIO.h>
#include <itkImageSeriesReader.h>
#include <itkGDCMSeriesFileNames.h>
#include <itkGDCMImageIO.h>
#include <itkImageFileWriter.h>
#include <itkMedianImageFilter.h>
#include <itkBilateralImageFilter.h>
#include <itkDiscreteGaussianImageFilter.h>
#include <itkBinaryThresholdImageFilter.h>
#include <itkInvertIntensityImageFilter.h>
#include <itkGradientMagnitudeRecursiveGaussianImageFilter.h>
#include <itkLaplacianImageFilter.h>
#include <itkLaplacianSharpeningImageFilter.h>
#include <itkSobelEdgeDetectionImageFilter.h>
#include <itkResampleImageFilter.h>
#include <itkNearestNeighborInterpolateImageFunction.h>
#include <itkCastImageFilter.h>
#include <itkLinearInterpolateImageFunction.h>
#include <itkAddImageFilter.h>
#include <itkSubtractImageFilter.h>
#include <itkMultiplyImageFilter.h>
#include <itkDivideImageFilter.h>
#include <itkOrImageFilter.h>
#include <itkAndImageFilter.h>
#include <itkXorImageFilter.h>
#include <itkFlipImageFilter.h>
#include <itkImageFileReader.h>
#include <itkMaskImageFilter.h>
#include <itkHistogramMatchingImageFilter.h>
#include <itkRescaleIntensityImageFilter.h>
#include <itkExceptionObject.h>
#include <itkCropImageFilter.h>
#include <itkBoundingBox.h>
#include <itkCommand.h>
#include "itkMRIBiasFieldCorrectionFilter.h"
#include "itkImageRegionIteratorWithIndex.h"
#include "itkImageFileWriter.h"
#include "itkSphereSpatialFunction.h"
#include "itkMersenneTwisterRandomVariateGenerator.h"
#include "itkMultivariateLegendrePolynomial.h" 
#include "itkWarpImageFilter.h"
#include <itkNormalizeImageFilter.h>
#include "itkFilterWatcher.h"
#include <itkGDCMSeriesFileNames.h>
#include <itkImageSeriesReader.h>
#include <itkImageFileReader.h>
#include <itkNrrdImageIO.h>
#include <itkImageFileWriter.h>
#include <itkImageRegionIterator.h>
#include <itkImageDuplicator.h>
#include "itkGDCMImageIO.h"
#include <itkBoundingBox.h>
#include <itkCommand.h>
#include "itkConnectedThresholdImageFilter.h"
#include "itkDCMTKFileReader.h"
//#include "itkExtractChannelFromRgbaImageFilter.h"



//VTK
#include "mitkVtkPropRenderer.h"
#include <vtkCubeSource.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkMarchingCubes.h>
#include <vtkSTLWriter.h>
#include <vtkImageData.h>
#include <vtkRendererCollection.h>
#include <vtkProperty.h>
#include <vtkSmartPointer.h>
#include <vtkViewport.h>
#include <vtkCollection.h>
#include <vtkAssemblyPaths.h>
#include <vtkScalarBarActor.h>
#include <vtkActor2DCollection.h>
#include <vtkLookupTable.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include "vtkCamera.h"
#include "vtkImageWriter.h"
#include <vtkRenderer.h>
#include "vtkJPEGWriter.h"
#include "vtkPNGWriter.h"
#include "vtkRenderLargeImage.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkTestUtilities.h"
#include <vtkActor.h>
#include "vtkMitkRenderProp.h"
#include <vtkInteractorStyleTrackballCamera.h>
#include "vtkTextActor.h"
#include "vtkTextProperty.h"
#include "vtkPointPicker.h"
#include <vtkSphereSource.h>
#include <vtkCellPicker.h>
#include <vtkCommand.h>
#include <vtkCubeSource.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkPlaneWidget.h>
#include <vtkProperty.h>
#include <vtkSmartPointer.h>
#include <vtkTransform.h>
#include <vtkTransformFilter.h>


//dcmtk
#include "dcmtk/config/osconfig.h"  
#include "dcmtk/ofstd/ofstream.h"
#include "dcmtk/dcmdata/dcuid.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmsr/dsriodcc.h"
//#include "dcmtk/dcmsr/dsrdoc.h"

//pet
#include "USToolKitView.h"


//PK Modeling
#include "mitkWorkbenchUtil.h"
#include "mitkAterialInputFunctionGenerator.h"
#include "mitkOneTissueCompartmentModelFactory.h"
#include "mitkOneTissueCompartmentModelParameterizer.h"
#include "mitkExtendedOneTissueCompartmentModelFactory.h"
#include "mitkExtendedOneTissueCompartmentModelParameterizer.h"
#include "mitkTwoTissueCompartmentFDGModelFactory.h"
#include "mitkTwoTissueCompartmentFDGModelParameterizer.h"
#include "mitkTwoTissueCompartmentModelFactory.h"
#include "mitkTwoTissueCompartmentModelParameterizer.h"
#include "mitkNumericTwoTissueCompartmentModelFactory.h"
#include "mitkNumericTwoTissueCompartmentModelParameterizer.h"
#include <mitkPixelBasedParameterFitImageGenerator.h>
#include <mitkROIBasedParameterFitImageGenerator.h>
#include <mitkLevenbergMarquardtModelFitFunctor.h>
#include <mitkSumOfSquaredDifferencesFitCostFunction.h>
#include <mitkSquaredDifferencesFitCostFunction.h>
#include <mitkChiSquareFitCostFunction.h>
#include <mitkReducedChiSquareFitCostFunction.h>
#include <mitkSimpleBarrierConstraintChecker.h>
#include <mitkModelFitResultHelper.h>
#include <mitkImageTimeSelector.h>
#include <mitkMaskedDynamicImageStatisticsGenerator.h>
#include <mitkExtractTimeGrid.h>
#include <mitkInitialParameterizationDelegateBase.h>
#include <QThreadPool>
#include <QmitkDataStorageComboBox.h>
#include <boost/tokenizer.hpp>


#include <io.h>
#include <mpfit.h>


const std::string USToolKitView::VIEW_ID = "org.mitk.views.USToolKit";


void USToolKitView::SetFocus()
{

}


void USToolKitView::CreateQtPartControl(QWidget *parent)
{
	m_Controls.setupUi(parent);
	//image type select
	m_Controls.DCEUSDynamicGroupBox->setVisible(false);
	m_Controls.DCEUSStaticGroupBox->setVisible(false);
	m_Controls.ColorUSGroupBox->setVisible(false);

	connect(m_Controls.USLoadDiocmButton, SIGNAL(clicked()), this, SLOT(LoadDicomUS()));

	//combox predicate
	mitk::NodePredicateProperty::Pointer m_IsBinaryPredicate = mitk::NodePredicateProperty::New("binary", mitk::BoolProperty::New(true));
	mitk::NodePredicateAnd::Pointer m_IsASegmentationImagePredicate = mitk::NodePredicateAnd::New(m_IsBinaryPredicate, mitk::TNodePredicateDataType<mitk::Image>::New());
	mitk::NodePredicateNot::Pointer m_IsNotBinaryPredicate = mitk::NodePredicateNot::New(m_IsBinaryPredicate);
	mitk::NodePredicateAnd::Pointer m_IsOfTypeImagePredicate = mitk::NodePredicateAnd::New(m_IsNotBinaryPredicate, mitk::TNodePredicateDataType<mitk::Image>::New());

	//get loaded data
	m_Controls.USPreprocessDataSelectionComBox->setInsertPolicy(QComboBox::InsertAlphabetically);
	m_Controls.USPreprocessDataSelectionComBox->SetDataStorage(this->GetDataStorage());
	m_Controls.USPreprocessDataSelectionComBox->SetPredicate(m_IsOfTypeImagePredicate);
	m_Controls.USPreprocessDataSelectionComBox->SetAutoSelectNewItems(false);

	//Get ROI：
	//fererence
	m_Controls.USReferenceSelectorCombox->setInsertPolicy(QComboBox::InsertAlphabetically);
	m_Controls.USReferenceSelectorCombox->SetDataStorage(this->GetDataStorage());
	m_Controls.USReferenceSelectorCombox->SetPredicate(m_IsOfTypeImagePredicate);
	m_Controls.USReferenceSelectorCombox->SetAutoSelectNewItems(false);
	//lesion
	m_Controls.USLesionSelectorCombox->setInsertPolicy(QComboBox::InsertAlphabetically);
	m_Controls.USLesionSelectorCombox->SetDataStorage(this->GetDataStorage());
	m_Controls.USLesionSelectorCombox->SetPredicate(m_IsOfTypeImagePredicate);
	m_Controls.USLesionSelectorCombox->SetAutoSelectNewItems(false);

	//connect(m_Controls.USReferenceSelectorCombox_3, SIGNAL(activated(int)), this, SLOT(USReferenceDataSelection(int)));
	//connect(m_Controls.USLesionSelectorCombox_2, SIGNAL(activated(int)), this, SLOT(USLesionDataSelection(int)));
	connect(m_Controls.USSequenceEditSlider, SIGNAL(valueChanged(int)), this, SLOT(USSequenceEdit(int)));
	connect(m_Controls.USRGBConvertGrayButton, SIGNAL(clicked()), this, SLOT(USRGBConvertGray()));
	connect(m_Controls.USConvertEPButton, SIGNAL(clicked()), this, SLOT(USConvertToEchoPower()));
	connect(m_Controls.USDenoiseStartButton, SIGNAL(clicked()), this, SLOT(USDenoiseStart()));
	connect(m_Controls.USQuantitationButton, SIGNAL(clicked()), this, SLOT(USQuantitation()));
	connect(m_Controls.DCEUSDynamicCheckbox, SIGNAL(clicked()), this, SLOT(DCEUSDynamicDisply()));
	connect(m_Controls.DCEUSStaticCheckbox, SIGNAL(clicked()), this, SLOT(DCEUSStaticDisply()));
	connect(m_Controls.ColorUSCheckbox, SIGNAL(clicked()), this, SLOT(ColorUSDisply()));
}


USToolKitView::USToolKitView(QObject *)
	: QmitkAbstractView()
{

}


USToolKitView::~USToolKitView()
{

}


void USToolKitView::OnSelectionChanged(berry::IWorkbenchPart::Pointer /*source*/,
	const QList<mitk::DataNode::Pointer>& nodes)
{

}


void USToolKitView::ReadImageFromFolder(const QString & path) {
	QDir dir(path);
	if (!dir.exists()) {
		QMessageBox::information(NULL, "Warning", "The loaded path is uncorrect!");
		return;
	}

	dir.setFilter(QDir::Dirs | QDir::Files);
	dir.setSorting(QDir::DirsFirst);
	QFileInfoList list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
	int i = 0;

	while (i < list.size()) {
		QFileInfo fileInfo = list.at(i);

		if (fileInfo.fileName() == ".")
		{
			i++;
			continue;
		}

		if (fileInfo.fileName() == "..") {
			i++;
			continue;
		}

		if (fileInfo.suffix() == "txt") {
			i++;
			continue;
		}

		if (fileInfo.suffix() == "xls") {
			i++;
			continue;
		}
		if (fileInfo.suffix() == "csv") {
			i++;
			continue;
		}
		if (fileInfo.suffix() == "jpg") {
			i++;
			continue;
		}

		if (fileInfo.suffix() == "png") {
			i++;
			continue;
		}

		if (fileInfo.suffix() == "pf") {
			i++;
			continue;
		}

		if (fileInfo.suffix() == "xml") {
			i++;
			continue;
		}
		if (fileInfo.suffix() == "doc") {
			i++;
			continue;
		}		
		if (fileInfo.suffix() == "docx") {
			i++;
			continue;
		}
		bool bisDir = fileInfo.isDir(); // check: folder includes folder

		if (bisDir)
		{
			ReadImageFromFolder(fileInfo.filePath());

		}
		else
		{
			int i = 0;
			QString dataPath = fileInfo.path();
			QString fileName = fileInfo.fileName();


			int lastindex = fileName.lastIndexOf(".");
			QString dataName = fileName.mid(0, lastindex);

			MITK_INFO << "Path: " << dataPath.toStdString();
			MITK_INFO << "FileName: " << fileName.toStdString();
			MITK_INFO << "DataName: " << dataName.toStdString();

			multiUSFileName.push_back(fileName);
			multiUSDataPath.push_back(dataPath);
			multiUSDataName.push_back(dataName);

			//break;
		}
		i++;
	}
}


template<typename TImageType>
mitk::Image::Pointer USToolKitView::ReadRGBImageFileByITK(const std::string filename)
{

	typedef itk::ImageFileReader<TImageType> ReaderType;
	ReaderType::Pointer reader = ReaderType::New();
	reader->SetFileName(filename);

	try
	{
		reader->Update();
	}
	catch (itk::ExceptionObject &excp)
	{
		MITK_INFO << "Exception thrown while reading the series ";
		MITK_INFO << excp;
	}

	mitk::Image::Pointer image = mitk::Image::New();
	mitk::CastToMitkImage(reader->GetOutput(), image);
	return image;
}


void USToolKitView::LoadDicomUS() {


	QSettings appSettings;
	QString filepath;
	//get the filepath from dialog
	filepath = QFileDialog::getExistingDirectory(0, tr("Load Multiple Folders File"), appSettings.value(m_DEFAULT_DIR_KEY).toString(), 0);
	MITK_INFO << "FilePath is: " << filepath.toStdString() << endl;
	if (filepath == NULL)
	{
		return;
	}

	QFileInfo fileinfo(filepath);
	if (fileinfo.isDir())
		appSettings.setValue(m_DEFAULT_DIR_KEY, fileinfo.absoluteFilePath());
	else
		appSettings.setValue(m_DEFAULT_DIR_KEY, fileinfo.absolutePath());

	// Read Folder
	multiUSFileName.clear();
	multiUSDataPath.clear();
	multiUSDataName.clear();

	ReadImageFromFolder(filepath);

	int phase = multiUSDataName.size();

	////°´Ë³ÐòÊý¾Ý¼ÓÔØ
	mitk::LevelWindow levelwindow;
	levelwindow.SetLevelWindow(128, 256);


	for (int i = 0; i < phase; i++) {

		//Â·¾¶
		std::string pathImage = (multiUSDataPath[i]).toStdString() + "/" + (multiUSFileName[i]).toStdString();
		
		DcmFileFormat dfile;
		OFCondition status = dfile.loadFile(OFFilename(pathImage.c_str()));
		MITK_INFO << pathImage.c_str();
		if (status.bad())
		{
			MITK_INFO << "No dicom to load";
			return;
		}
		DcmDataset *data = dfile.getDataset();
		#define DCM_FrameTimeVector  DcmTagKey(0x0018, 0x1065)
		OFString FrameTimeVector;
		data->findAndGetOFStringArray(DCM_FrameTimeVector, FrameTimeVector);
		std::string dataFrameTimeVector = FrameTimeVector.c_str();
		//ÏñËØÀàÐÍ
		typedef itk::GDCMImageIO DcmIoType;
		DcmIoType::Pointer io = DcmIoType::New();
		if (io->CanReadFile(pathImage.c_str()))
		{
			io->SetFileName(pathImage.c_str());
			io->ReadImageInformation();

			mitk::Image::Pointer image = mitk::Image::New();

			if (io->GetPixelType() == itk::ImageIOBase::SCALAR)
			{
				//MITK_INFO << "ImageType is SCALAR";

				switch (io->GetComponentType())
				{
				case DcmIoType::UCHAR:
					image = ReadRGBImageFileByITK< itk::Image< unsigned char, 3>  >(pathImage);
					break;
				case DcmIoType::CHAR:
					image = ReadRGBImageFileByITK< itk::Image<char, 3>  >(pathImage);
					break;
				case DcmIoType::USHORT:
					image = ReadRGBImageFileByITK< itk::Image<unsigned short, 3>  >(pathImage);
					break;
				case DcmIoType::SHORT:
					image = ReadRGBImageFileByITK< itk::Image<short, 3>  >(pathImage);
					break;
				case DcmIoType::UINT:
					image = ReadRGBImageFileByITK< itk::Image<unsigned int, 3>  >(pathImage);
					break;
				case DcmIoType::INT:
					image = ReadRGBImageFileByITK< itk::Image<int, 3>  >(pathImage);
					break;
				case DcmIoType::ULONG:
					image = ReadRGBImageFileByITK< itk::Image<long unsigned int, 3>  >(pathImage);
					break;
				case DcmIoType::LONG:
					image = ReadRGBImageFileByITK< itk::Image<long int, 3>  >(pathImage);
					break;
				case DcmIoType::FLOAT:
					image = ReadRGBImageFileByITK< itk::Image<float, 3>  >(pathImage);
					break;
				case DcmIoType::DOUBLE:
					image = ReadRGBImageFileByITK< itk::Image<double, 3>  >(pathImage);
					break;
				default:
					image = ReadRGBImageFileByITK< itk::Image< unsigned char, 3>  >(pathImage);
					break;
				}


			}
			else if (io->GetPixelType() == itk::ImageIOBase::RGB)
			{
				MITK_INFO << "ImageType is RGB";
				unsigned int dims = io->GetNumberOfDimensions();
				//MITK_INFO << "ImageDims is " << dims;
				MITK_INFO << io->GetComponentType();
				switch (io->GetComponentType())
				{
				case DcmIoType::UCHAR:
					image = ReadRGBImageFileByITK< itk::Image< itk::RGBPixel<unsigned char>, 3>  >(pathImage);
					break;
				case DcmIoType::CHAR:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<char>, 3>  >(pathImage);
					break;
				case DcmIoType::USHORT:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<unsigned short>, 3>  >(pathImage);
					break;
				case DcmIoType::SHORT:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<short>, 3>  >(pathImage);
					break;
				case DcmIoType::UINT:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<unsigned int>, 3>  >(pathImage);
					break;
				case DcmIoType::INT:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<int>, 3>  >(pathImage);
					break;
				case DcmIoType::ULONG:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<long unsigned int>, 3>  >(pathImage);
					break;
				case DcmIoType::LONG:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<long int>, 3>  >(pathImage);
					break;
				case DcmIoType::FLOAT:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<float>, 3>  >(pathImage);
					break;
				case DcmIoType::DOUBLE:
					image = ReadRGBImageFileByITK< itk::Image<itk::RGBPixel<double>, 3>  >(pathImage);
					break;
				default:
					image = ReadRGBImageFileByITK< itk::Image< itk::RGBPixel<unsigned char>, 3>  >(pathImage);
					break;
				}
			}
			else
			{
				continue;
			}

			if (this->GetDataStorage()->GetNamedNode(multiUSDataName[i].toStdString()))
				this->GetDataStorage()->Remove(this->GetDataStorage()->GetNamedNode(multiUSDataName[i].toStdString()));

			mitk::DataNode::Pointer node = mitk::DataNode::New();
			node->SetData(image);
			node->SetStringProperty("Timevector", dataFrameTimeVector.c_str());
			node->SetName(multiUSDataName[i].toStdString());
			node->SetLevelWindow(levelwindow);
			this->GetDataStorage()->Add(node);
			this->GlobalReinit(true);


		}
		else {
			continue;
		}

	}

}


void USToolKitView::ShowOnlySelectedNodes(const mitk::DataNode* selectedNode)
{
	mitk::DataStorage::SetOfObjects::ConstPointer _NodeSet = this->GetDataStorage()->GetAll();
	if (!_NodeSet)
	{
		return;
	}

	mitk::DataNode* node;
	for (mitk::DataStorage::SetOfObjects::ConstIterator it = _NodeSet->Begin(); it != _NodeSet->End(); it++)
	{
		node = const_cast<mitk::DataNode*>(it->Value().GetPointer());
		if (!node)
		{
			return;
		}

		node->SetVisibility(selectedNode == node);
	}

	mitk::RenderingManager::GetInstance()->RequestUpdateAll();

}


void USToolKitView::GlobalReinit(bool)
{
	mitk::IRenderWindowPart* renderWindow = this->GetRenderWindowPart();

	// no render window available
	if (renderWindow == nullptr) return;

	// get all nodes that have not set "includeInBoundingBox" to false
	mitk::NodePredicateNot::Pointer pred
		= mitk::NodePredicateNot::New(mitk::NodePredicateProperty::New("includeInBoundingBox"
			, mitk::BoolProperty::New(false)));

	mitk::DataStorage::SetOfObjects::ConstPointer rs = this->GetDataStorage()->GetSubset(pred);
	// calculate bounding geometry of these nodes
	auto bounds = this->GetDataStorage()->ComputeBoundingGeometry3D(rs, "visible");

	// initialize the views to the bounding geometry
	renderWindow->GetRenderingManager()->InitializeViews(bounds);


}


void USToolKitView::USReferenceDataSelection(int index) {

	mitk::DataNode* node = m_Controls.USReferenceSelectorCombox->GetSelectedNode();
	cout << "nodename: " << node->GetName() << endl;

	if (!node) return;

	this->ShowOnlySelectedNodes(node);

	this->GlobalReinit(true);
	mitk::RenderingManager::GetInstance()->RequestUpdateAll();
}


void USToolKitView::USLesionDataSelection(int index) {

	mitk::DataNode* node = m_Controls.USLesionSelectorCombox->GetSelectedNode();
	cout << "nodename: " << node->GetName() << endl;

	if (!node) return;

	this->ShowOnlySelectedNodes(node);

	this->GlobalReinit(true);
	mitk::RenderingManager::GetInstance()->RequestUpdateAll();
}


void USToolKitView::USSequenceEdit(int index)
{

}


void USToolKitView::USRGBConvertGray()
{
	mitk::DataNode* node = m_Controls.USPreprocessDataSelectionComBox->GetSelectedNode();
	if (!node)
		return;

	mitk::Image::Pointer mitkItkImage = dynamic_cast<mitk::Image*>(node->GetData());
	if (!mitkItkImage)
		return;

	typedef itk::Image<unsigned char, 3> charImageType;
	typedef itk::RGBPixel<unsigned char> PixelType;
	typedef itk::Image< PixelType, 3 > ItkRgbImageType;
	typedef mitk::ImageToItk< ItkRgbImageType > CasterType;
	//original itk data
	CasterType::Pointer caster = CasterType::New();
	caster->SetInput(mitkItkImage);
	caster->Update();
	ItkRgbImageType::Pointer itkInImage = caster->GetOutput();

	//define some generated itk data
	charImageType::RegionType newRegion;
	charImageType::SizeType newSize = itkInImage->GetLargestPossibleRegion().GetSize();
	newRegion.SetSize(itkInImage->GetLargestPossibleRegion().GetSize());
	newRegion.SetIndex(itkInImage->GetLargestPossibleRegion().GetIndex());

	charImageType::SpacingType newSpacing;
	newSpacing[0] = itkInImage->GetSpacing()[0];
	newSpacing[1] = itkInImage->GetSpacing()[1];
	newSpacing[2] = itkInImage->GetSpacing()[2];

	charImageType::Pointer greyImage = charImageType::New();
	greyImage->SetRegions(newRegion);
	greyImage->SetSpacing(newSpacing);
	greyImage->SetOrigin(itkInImage->GetOrigin());
	greyImage->SetDirection(itkInImage->GetDirection());
	greyImage->Allocate();

	int x = mitkItkImage->GetDimensions()[0];
	int y = mitkItkImage->GetDimensions()[1];
	int z = mitkItkImage->GetDimensions()[2];

	MITK_INFO << "dimensions: " << x << " " << y << " " << z;

	// calculate the gray Image
	typedef itk::ImageRegionConstIterator< ItkRgbImageType > ConstIteratorType;
	typedef itk::ImageRegionIterator< charImageType > IteratorType;
	ConstIteratorType in(itkInImage, itkInImage->GetRequestedRegion());
	IteratorType out(greyImage, greyImage->GetRequestedRegion());

	for (in.GoToBegin(), out.GoToBegin(); !in.IsAtEnd(); ++in, ++out)
	{
		out.Set((in.Get().GetRed() * 30 + in.Get().GetGreen() * 59 + in.Get().GetBlue() * 11 + 50) / 100.0);
	}

	// add the gray image to main node
	mitk::Image::Pointer greyMitkImage = mitk::Image::New();
	mitk::CastToMitkImage(greyImage, greyMitkImage);
	mitk::DataNode::Pointer newNode = mitk::DataNode::New();
	newNode->SetData(greyMitkImage);
	newNode->SetName("_gray");
	this->GetDataStorage()->Add(newNode, node);

}


void USToolKitView::USConvertToEchoPower()
{
	mitk::DataNode* node = m_Controls.USPreprocessDataSelectionComBox->GetSelectedNode();
	if (!node)
		return;

	mitk::Image::Pointer mitkInImage = dynamic_cast<mitk::Image*>(node->GetData());
	if (!mitkInImage)
		return;

	typedef itk::Image< double, 3 > EPImageType;
	typedef itk::Image< unsigned char, 3 > charImageType;
	typedef itk::RGBPixel< unsigned char > PixelType;
	typedef itk::Image< PixelType, 3 > ItkRgbImageType;
	typedef mitk::ImageToItk< ItkRgbImageType > CasterType;
	//original itk data
	CasterType::Pointer caster = CasterType::New();
	caster->SetInput(mitkInImage);
	caster->Update();
	ItkRgbImageType::Pointer itkInImage = caster->GetOutput();

	//define some generated itk data
	EPImageType::RegionType newRegion;
	EPImageType::SizeType newSize = itkInImage->GetLargestPossibleRegion().GetSize();
	newRegion.SetSize(itkInImage->GetLargestPossibleRegion().GetSize());
	newRegion.SetIndex(itkInImage->GetLargestPossibleRegion().GetIndex());

	EPImageType::SpacingType newSpacing;
	newSpacing[0] = itkInImage->GetSpacing()[0];
	newSpacing[1] = itkInImage->GetSpacing()[1];
	newSpacing[2] = itkInImage->GetSpacing()[2];

	EPImageType::Pointer EPItkImage = EPImageType::New();
	EPItkImage->SetRegions(newRegion);
	EPItkImage->SetSpacing(newSpacing);
	EPItkImage->SetOrigin(itkInImage->GetOrigin());
	EPItkImage->SetDirection(itkInImage->GetDirection());
	EPItkImage->Allocate();

	int x = mitkInImage->GetDimensions()[0];
	int y = mitkInImage->GetDimensions()[1];
	int z = mitkInImage->GetDimensions()[2];

	int Vmax = 32767;
	int DR = 60;

	// calculate the Echo power Image
	typedef itk::ImageRegionConstIterator< ItkRgbImageType > ConstIteratorType;
	typedef itk::ImageRegionIterator< EPImageType > IteratorType;
	ConstIteratorType in(itkInImage, itkInImage->GetRequestedRegion());
	IteratorType out(EPItkImage, itkInImage->GetRequestedRegion());
	double grayPixel;
	for (in.GoToBegin(), out.GoToBegin(); !in.IsAtEnd(); ++in, ++out)
	{
		grayPixel = (in.Get().GetRed() * 30 + in.Get().GetGreen() * 59 + in.Get().GetBlue() * 11 + 50) / 100.0;
		out.Set(pow(Vmax, 2) * pow(10, ((grayPixel / 255.0 - 1) * DR) / 10));
	}

	// add the gray image to main node
	mitk::Image::Pointer EPMitkImage = mitk::Image::New();
	mitk::CastToMitkImage(EPItkImage, EPMitkImage);
	mitk::DataNode::Pointer newNode = mitk::DataNode::New();
	newNode->SetData(EPMitkImage);
	newNode->SetName(node->GetName()+"_Echo_Power");
	this->GetDataStorage()->Add(newNode, node);
}


void USToolKitView::USDenoiseStart()
{

}


void USToolKitView::DCEUSDynamicDisply()
{
	m_Controls.DCEUSDynamicGroupBox->setVisible(true);
	m_Controls.DCEUSStaticGroupBox->setVisible(false);
	m_Controls.ColorUSGroupBox->setVisible(false);
}


void USToolKitView::DCEUSStaticDisply()
{
	m_Controls.DCEUSStaticGroupBox->setVisible(true);
	m_Controls.DCEUSDynamicGroupBox->setVisible(false);
	m_Controls.ColorUSGroupBox->setVisible(false);
}


void USToolKitView::ColorUSDisply()
{
	m_Controls.ColorUSGroupBox->setVisible(true);
	m_Controls.DCEUSDynamicGroupBox->setVisible(false);
	m_Controls.DCEUSStaticGroupBox->setVisible(false);
}


void USToolKitView::USExtractROI()
{

}


void USToolKitView::USGetTimeData(mitk::DataNode *dataNode, double *tempGrid)
{
	std::string timepoints;
	dataNode->GetStringProperty("Timevector", timepoints);
	timepoints.push_back('\\');
	std::string tempstring;
	double tempvalue;
	int count = 0;
	// extract the number from time points vector which looks like "0\115\115\116"
	for (auto ch : timepoints)
	{
		if (ch == '\\') {
			cout << tempstring << endl;
			*tempGrid = stod(tempstring) / 1000;
			++tempGrid;
			++count;
			tempstring.clear();
			continue;
		}
		tempstring.push_back(ch);
	}
	// convert the int vector to continious time sequence
	for (int i = 0; i < count; i++)
	{
		if (i == 0)
		{
			tempGrid[i] = 0;
			continue;
		}
		tempGrid[i] = tempGrid[i - 1] + tempGrid[i];
	}
}


// apply the fitted model parameter
int gammaVariateFit(int m, int n, double *p, double *dy, double **dvec, void *vars)
{
	struct vars_struct *v = (struct vars_struct *) vars;
	double *x, *y;

	x = v->n;
	y = v->value;

	//defined as in DCEMRIS4
	//A:    max flow concentration
	//ka:    inflow factor of bolus tracer
	//at:    arrival time of bolus influx
	//ta:    time of half tracers into the capilary bed
	//kb outflow factor
	//tb:    time-course of bolus passing through the capilary
	//MTT = tb - at
	double k = p[0], alpha = p[1], beta = p[2];//,t0 = p[1];
	double deltaT = x[2] - x[1];
	double maxY1 = 0;
	int Yargmax1;



	for (int i = 0; i < m; i++)
	{
		if (y[i] > maxY1)
		{
			maxY1 = y[i];
			Yargmax1 = i;
		}
	}



	double  prevalue1 = 0;
	int Preargmax1 = 0;
	for (int i = 0; i < m / 2; i++)
	{
		if (y[i] < (maxY1*0.1))
		{
			prevalue1 = y[i];
			Preargmax1 = i;
		}
	}



	memset(dy, 0, sizeof(double)*m);
	for (int t = 0; t < m; t++)
	{
		double dT = x[t] - x[Preargmax1];
		if (dT > 0)
		{
			dy[t] = k * (pow(dT, alpha))*(exp(-dT / beta));
		}
		else
			dy[t] = 0;
	}



	return 0;
}


// modify the model parameter
int gammaVariate(int m, int n, double *p, double *dy, double **dvec, void *vars)
{
	struct vars_struct *v = (struct vars_struct *) vars;
	double *x, *y;

	x = v->n;
	y = v->value;

	//defined as in DCEMRIS4
	//A: max flow concentration
	//ka: inflow factor of bolus tracer
	//at: arrivaal time of bolus influx
	//ta: time of half tracers into the capilary bed
	//kb outflow factor
	//tb: time-course of bolus passing through the capilary
	//MTT = tb - at
	double k = p[0], alpha = p[1], beta = p[2];//, t0 = p[1];

	double deltaT = x[2] - x[1];
	double maxY1 = 0;

	int Yargmax1;
	for (int i = 0; i < m; i++)
	{
		if (y[i] > maxY1)
		{
			maxY1 = y[i];
			Yargmax1 = i;
		}
	}


	double  prevalue1 = 0;
	int Preargmax1 = 0;
	for (int i = 0; i < m / 2; i++)
	{
		if (y[i] < (maxY1*0.1))
		{
			prevalue1 = y[i];
			Preargmax1 = i;
		}
	}


	memset(dy, 0, sizeof(double)*m);
	for (int t = 0; t < m; t++)
	{
		//double dT = t*deltaT-t0;
		double dT = x[t] - x[Preargmax1];
		if (dT > 0)
		{
			dy[t] = y[t] - k * (pow(dT, alpha))*(exp(-dT / beta));
		}
		else
			dy[t] = 0;
	}
	return 0;
}


// fit the model
void USToolKitView::USModelFit(int timeSteps, double *t, double *EP, double *fit)
{
	// y[] : original column
	double concMax = 0;
	MITK_INFO << "======== concMax ：";
	for (int i = 0; i < timeSteps; i++)
	{
		if (concMax < EP[i])
		{
			concMax = EP[i];
		}
	}

	//double *t1 = new double[timeSteps];
	//double *fit = new double[timeSteps];
	double *time2 = new double[timeSteps];
	//double *y1 = new double[timeSteps];

	// related to gamma 
	const int NumParams = 3;            //2 for Patlak, leave the other 3 there for future possible models
	mp_par pars[NumParams];                /* Parameter constraints */
	memset(pars, 0, sizeof(pars));        /* Initialize constraint structure */

	//use gamma variate fit to find BAT, TTP and AUC90, 180
	pars[0].limited[0] = 1;
	pars[0].limits[0] = 0;
	pars[0].limited[1] = 1;
	pars[0].limits[1] = concMax * 2;

	//alpha constraint
	pars[1].limited[0] = 1;
	pars[1].limits[0] = 0;
	pars[1].limited[1] = 1;
	pars[1].limits[1] = 3;

	//beta constraint
	pars[2].limited[0] = 1;
	pars[2].limits[0] = 0;
	pars[2].limited[1] = 1;
	pars[2].limits[1] = 50;

	double p[] = { 1, 1, 1 };

	struct vars_struct v;

	mp_result result;
	memset(&result, 0, sizeof(result));

	// adapt time interval 
	for (int i = 0; i < timeSteps; i++)
	{
		time2[i] = t[i] / t[timeSteps - 1] * timeSteps;
	}

	v.n = time2;
	v.value = EP;

	mpfit(gammaVariate, timeSteps, 3, p, pars, 0, (void *)&v, &result);
	MITK_INFO << "A: " << p[0] << " , alpha: " << p[1] << " , beta: " << p[2];

	gammaVariateFit(timeSteps, 3, p, fit, 0, (void *)&v);


	MITK_INFO << "Finish Gamma Fit";
}


// plot the curve
void USToolKitView::USCurveTIC(std::vector<double> tempGrid, std::vector<double> statisticsMean, std::vector<double> fit)
{
	m_Controls.USSignalCurveWidgetPlot->Clear();

	std::string xAxis = "Time[s]";
	std::string yAxis = "Echo power";
	std::string plotTitle = "TIC Plot";

	m_Controls.USSignalCurveWidgetPlot->SetAxisTitle(QwtPlot::xBottom, xAxis.c_str());
	m_Controls.USSignalCurveWidgetPlot->SetAxisTitle(QwtPlot::yLeft, yAxis.c_str());
	m_Controls.USSignalCurveWidgetPlot->SetPlotTitle(plotTitle.c_str());

	unsigned int curveId = this->m_Controls.USSignalCurveWidgetPlot->InsertCurve("TIC");
	unsigned int curveFitId = this->m_Controls.USSignalCurveWidgetPlot->InsertCurve("Fit");

	QPen pen(Qt::DashLine);
	pen.setWidth(1);
	pen.setColor(Qt::green);
	QPen penfit(Qt::SolidLine);
	penfit.setWidth(1);
	penfit.setColor(Qt::red);

	m_Controls.USSignalCurveWidgetPlot->SetCurveData(curveId, tempGrid, statisticsMean);
	m_Controls.USSignalCurveWidgetPlot->SetCurvePen(curveId, pen);
	m_Controls.USSignalCurveWidgetPlot->SetCurveStyle(curveId, QwtPlotCurve::Lines);
	m_Controls.USSignalCurveWidgetPlot->SetCurveData(curveFitId, tempGrid, fit);
	m_Controls.USSignalCurveWidgetPlot->SetCurvePen(curveFitId, penfit);
	m_Controls.USSignalCurveWidgetPlot->SetCurveStyle(curveFitId, QwtPlotCurve::Lines);
	m_Controls.USSignalCurveWidgetPlot->Replot();

	this->GlobalReinit(true);

}


void CalculateSlop(std::vector<double> timeGrid, std::vector<double> fit, double* slop)
{
	for (int i = 0; i < timeGrid.size() - 1; ++i)
	{
		double dx = timeGrid[i + 1] - timeGrid[i];
		double dy = fit[i + 1] - fit[i];
		slop[i] = dy/dx;
	}
	slop[timeGrid.size()-1] = slop[timeGrid.size() - 2];
}

double CalculateAUC(std::vector<double> timeGrid, std::vector<double> fit, int ti, int to)
{
	double Auc=0.0;
	if (ti < 0) ti = 0;
	for (int i = ti; i < to; ++i)
	{
		double dx = timeGrid[i + 1] - timeGrid[i];
		double dy = fit[i + 1] - fit[i];
		double intI = (1 / 2) * dx * dy + fit[i] * dx;

		Auc += std::abs(intI);
	}
	MITK_INFO << Auc;
	return Auc;
}


void USToolKitView::USCalculateParam(std::vector<double> timeGrid, std::vector<double> fit, CBParam *BP)
{
	memset(BP, 0, sizeof(*BP));
	std::vector<double> slop(timeGrid.size());
	BP->PE = *std::max_element(fit.begin(), fit.end());
	int TTPIdx = std::max_element(fit.begin(), fit.end()) - fit.begin();
	BP->TTP = timeGrid[TTPIdx];
	
	MITK_INFO << "begin to slop";
	CalculateSlop(timeGrid, fit, &slop[0]);
	MITK_INFO << "begin to slop plobkem";
	int WiRIdx = std::max_element(slop.begin(), slop.end()) - slop.begin();
	int WoRIdx = std::min_element(slop.begin(), slop.end()) - slop.begin();
	double Ti = timeGrid[WiRIdx] - fit[WiRIdx] / slop[WiRIdx];
	double To = timeGrid[WoRIdx] - fit[WoRIdx] / slop[WoRIdx];
	MITK_INFO << WiRIdx;
	MITK_INFO << Ti;
	int TiIdx = Ti / (timeGrid[1] - timeGrid[0]);
	int ToIdx = To / (timeGrid[1] - timeGrid[0]);
	MITK_INFO << ToIdx;
	MITK_INFO << "begin AUC";
	BP->WiAUC = CalculateAUC(timeGrid, fit, TiIdx, TTPIdx);
	BP->WoAUC = CalculateAUC(timeGrid, fit, TTPIdx, ToIdx);
	BP->WiWoAUC = BP->WiAUC + BP->WoAUC;
	BP->WiR = *std::max_element(slop.begin(), slop.end());
	BP->WoR = *std::min_element(slop.begin(), slop.end());
	BP->RT = BP->TTP - Ti;
	BP->FT = To - BP->TTP;
	BP->WiPI = BP->WiAUC / BP->RT;
}


void USToolKitView::USShowParamTable(CBParam *BP)
{
	QString QparaName = m_Controls.USParameterSelectorComboBox->currentText();
	std::string paramName = QparaName.toStdString();
	if (paramName == "PE")
	{
		m_Controls.USParamtableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(BP->PE)));
	}
}


void USToolKitView::USQuantitation()
{
	//get ROI node
	mitk::DataNode* referNode = m_Controls.USReferenceSelectorCombox->GetSelectedNode();
	mitk::DataNode* lesionNode = m_Controls.USLesionSelectorCombox->GetSelectedNode();
	//get original image node
	mitk::DataNode* mainNode = m_Controls.USPreprocessDataSelectionComBox->GetSelectedNode();
	
	std::string nodeName = mainNode->GetName();
	//MITK_INFO << nodeName;

	if ((!referNode) || (!lesionNode) || (!mainNode)) return;

	//get the mitk ROI
	mitk::Image::Pointer referRoiMitkImage = dynamic_cast<mitk::Image*>(referNode->GetData());
	mitk::Image::Pointer lesionRoiMitkImage = dynamic_cast<mitk::Image*>(lesionNode->GetData());
	mitk::DataStorage::SetOfObjects::ConstPointer _NodeSets = m_Controls.USPreprocessDataSelectionComBox->GetNodes();
	for (mitk::DataStorage::SetOfObjects::ConstIterator it = _NodeSets->Begin(); it != _NodeSets->End(); ++it)
	{
		mitk::DataNode* dataNode = const_cast<mitk::DataNode*>(it->Value().GetPointer());
		std::string nodeName = dataNode->GetName();
		if (nodeName.length() < 10) continue;
		if ((!dataNode) || ((nodeName.substr(nodeName.length() - 10, nodeName.length()))!="Echo_Power")) continue;
		mitk::Image::Pointer EPMitkImage = dynamic_cast<mitk::Image*>(dataNode->GetData());
		MITK_INFO << nodeName;
		//convert to itk data
		typedef itk::Image<double, 3> charImageType;
		//itk ROI data
		charImageType::Pointer referRoiItkImage = charImageType::New();
		mitk::CastToItkImage(referRoiMitkImage, referRoiItkImage);
		charImageType::Pointer lesionRoiItkImage = charImageType::New();
		mitk::CastToItkImage(lesionRoiMitkImage, lesionRoiItkImage);
		//itk EP data
		charImageType::Pointer EPItkImage = charImageType::New();
		mitk::CastToItkImage(EPMitkImage, EPItkImage);

		//define some generated itk data
		charImageType::RegionType newRegion;
		charImageType::SizeType newSize = EPItkImage->GetLargestPossibleRegion().GetSize();
		newRegion.SetSize(EPItkImage->GetLargestPossibleRegion().GetSize());
		newRegion.SetIndex(EPItkImage->GetLargestPossibleRegion().GetIndex());

		charImageType::SpacingType newSpacing;
		newSpacing[0] = EPItkImage->GetSpacing()[0];
		newSpacing[1] = EPItkImage->GetSpacing()[1];
		newSpacing[2] = EPItkImage->GetSpacing()[2];


		charImageType::Pointer EPReferItkImage = charImageType::New();
		EPReferItkImage->SetRegions(newRegion);
		EPReferItkImage->SetSpacing(newSpacing);
		EPReferItkImage->SetOrigin(EPItkImage->GetOrigin());
		EPReferItkImage->SetDirection(EPItkImage->GetDirection());
		EPReferItkImage->Allocate();

		charImageType::Pointer EPLesionItkImage = charImageType::New();
		EPLesionItkImage->SetRegions(newRegion);
		EPLesionItkImage->SetSpacing(newSpacing);
		EPLesionItkImage->SetOrigin(EPItkImage->GetOrigin());
		EPLesionItkImage->SetDirection(EPItkImage->GetDirection());
		EPLesionItkImage->Allocate();

		//get the dimensions of origianal image and set some parameter
		int x = EPMitkImage->GetDimensions()[0];
		int y = EPMitkImage->GetDimensions()[1];
		int z = EPMitkImage->GetDimensions()[2];
		int Vmax = 32767;
		int DR = 60;
		int RoiSlice;

		// get the RoiSlice Position
		charImageType::IndexType RoiPixelIndex;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				for (int k = 0; k < z; k++) {
					RoiPixelIndex[0] = i;
					RoiPixelIndex[1] = j;
					RoiPixelIndex[2] = k;

					if (lesionRoiItkImage->GetPixel(RoiPixelIndex) > 0)
					{
						RoiSlice = k;
						break;
					};
				}
			}
		}
		MITK_INFO << RoiSlice;
		//**********extract ROI****************
		charImageType::IndexType EPPixelIndex;
		typedef double RoiPixelType;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				for (int k = 0; k < z; k++) {

					RoiPixelIndex[0] = i;
					RoiPixelIndex[1] = j;
					RoiPixelIndex[2] = RoiSlice;
					EPPixelIndex[0] = i;
					EPPixelIndex[1] = j;
					EPPixelIndex[2] = k;

					RoiPixelType EPItkPixel = EPItkImage->GetPixel(EPPixelIndex);
					RoiPixelType lesionItkPixel = lesionRoiItkImage->GetPixel(RoiPixelIndex);
					RoiPixelType referItkPixel = referRoiItkImage->GetPixel(RoiPixelIndex);
					EPLesionItkImage->SetPixel(EPPixelIndex, EPItkPixel*lesionItkPixel);
					EPReferItkImage->SetPixel(EPPixelIndex, EPItkPixel*referItkPixel);
				}
			}
		}

		//**********calculate the average EP************
		std::vector<double> EPAverageValue;
		double RoiPixelCount = 0;
		int RoiNum = 0;
		double sumOfSlice = 0;
		for (int k = 0; k < z; k++) {

			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {

					EPPixelIndex[0] = i;
					EPPixelIndex[1] = j;
					EPPixelIndex[2] = k;

					RoiPixelType EPLesionItkPixel = EPLesionItkImage->GetPixel(EPPixelIndex);
					if (EPLesionItkPixel > 0) {
						sumOfSlice = sumOfSlice + EPLesionItkPixel;
						RoiPixelCount++;
					}
				}
			}
			EPAverageValue.push_back(sumOfSlice / RoiPixelCount);
			sumOfSlice = 0;
			RoiNum = RoiPixelCount;
			RoiPixelCount = 0;
		}

		//************processing the time points*******************
		//std::vector<double> tempGrid;
		//USGetTimeData(dataNode, &tempGrid[0]);
		std::string timepoints;
		mainNode->GetStringProperty("Timevector", timepoints);
		timepoints.push_back('\\');
		std::string tempstring;
		std::vector<double> timeGrid;
		double tempvalue;
		for (auto ch : timepoints)
		{
			if (ch == '\\') {
				timeGrid.push_back(stod(tempstring) / 1000);
				tempstring.clear();
				continue;
			}
			tempstring.push_back(ch);
		}
		for (int i = 0; i < timeGrid.size(); i++)
		{
			if (i == 0)
			{
				timeGrid[i] = 0;
				continue;
			}
			timeGrid[i] = timeGrid[i - 1] + timeGrid[i];
		}

		//*******plot the curve************
		std::vector<double> fit(timeGrid.size());
		//fit the curve
		if ((!timeGrid.empty()) && (!EPAverageValue.empty()))
			USModelFit(timeGrid.size(), &timeGrid[0], &EPAverageValue[0], &fit[0]);

		USCurveTIC(timeGrid, EPAverageValue, fit);
		MITK_INFO << "plot done";
		//******calculate the curve parameter***********
		//CBParam *BP;
		//USCalculateParam(timeGrid, fit, BP);
		//MITK_INFO << "calcu done";
		//USShowParamTable(BP);

		//******display the generated image**********
		//mitk::Image::Pointer EPLesionMitkImage = mitk::Image::New();
		//mitk::CastToMitkImage(EPLesionItkImage, EPLesionMitkImage);

		//mitk::DataNode::Pointer EPLesionNode = mitk::DataNode::New();
		//EPLesionNode->SetData(EPLesionMitkImage);
		//EPLesionNode->SetName(nodeName + "_EPLesion");
		//this->GetDataStorage()->Add(EPLesionNode, dataNode);
		//MITK_INFO << "Quantitation done";
	}
}
