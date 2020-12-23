
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


const std::string USToolKitView::VIEW_ID = "org.mitk.views.USToolKit";


void USToolKitView::SetFocus()
{

}

void USToolKitView::CreateQtPartControl(QWidget *parent)
{
	m_Controls.setupUi(parent);
	connect(m_Controls.USLoadDynamicDicomButton, SIGNAL(clicked()), this, SLOT(LoadDicomUS()));

	//combox predicate
	mitk::NodePredicateProperty::Pointer m_IsBinaryPredicate = mitk::NodePredicateProperty::New("binary", mitk::BoolProperty::New(true));
	mitk::NodePredicateAnd::Pointer m_IsASegmentationImagePredicate = mitk::NodePredicateAnd::New(m_IsBinaryPredicate, mitk::TNodePredicateDataType<mitk::Image>::New());
	mitk::NodePredicateNot::Pointer m_IsNotBinaryPredicate = mitk::NodePredicateNot::New(m_IsBinaryPredicate);
	mitk::NodePredicateAnd::Pointer m_IsOfTypeImagePredicate = mitk::NodePredicateAnd::New(m_IsNotBinaryPredicate, mitk::TNodePredicateDataType<mitk::Image>::New());


	//get loaded data
	m_Controls.USLoadSelectorCombox->setInsertPolicy(QComboBox::InsertAlphabetically);
	m_Controls.USLoadSelectorCombox->SetDataStorage(this->GetDataStorage());
	m_Controls.USLoadSelectorCombox->SetPredicate(m_IsOfTypeImagePredicate);
	m_Controls.USLoadSelectorCombox->SetAutoSelectNewItems(false);

	//Get ROI：
	//fererence
	m_Controls.USReferenceSelectorCombox_3->setInsertPolicy(QComboBox::InsertAlphabetically);
	m_Controls.USReferenceSelectorCombox_3->SetDataStorage(this->GetDataStorage());
	m_Controls.USReferenceSelectorCombox_3->SetPredicate(m_IsOfTypeImagePredicate);
	m_Controls.USReferenceSelectorCombox_3->SetAutoSelectNewItems(false);
	//lesion
	m_Controls.USLesionSelectorCombox_2->setInsertPolicy(QComboBox::InsertAlphabetically);
	m_Controls.USLesionSelectorCombox_2->SetDataStorage(this->GetDataStorage());
	m_Controls.USLesionSelectorCombox_2->SetPredicate(m_IsOfTypeImagePredicate);
	m_Controls.USLesionSelectorCombox_2->SetAutoSelectNewItems(false);


	//connect(m_Controls.USReferenceSelectorCombox_3, SIGNAL(activated(int)), this, SLOT(USReferenceDataSelection(int)));
	//connect(m_Controls.USLesionSelectorCombox_2, SIGNAL(activated(int)), this, SLOT(USLesionDataSelection(int)));
	connect(m_Controls.USQuantitationButton, SIGNAL(clicked()), this, SLOT(USQuantitation()));
	//connect(m_Controls.USRGBConvertGrayButton, SIGNAL(clicked()), this, SLOT(USExtractChannel()));
	//connect(m_Controls.DCEUSDynamicCheckbox,)


}




USToolKitView::~USToolKitView()
{


}

USToolKitView::USToolKitView(QObject *)
	: QmitkAbstractView()

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
		int RowCount = m_Controls.USLoadTableWidget->rowCount();
		QString QdataFrameTimevector = QString::fromStdString(dataFrameTimeVector);
		QString QgroupElement = "(0x0018, 0x1065)";
		QString Qdiscription = "FrameTimeVector";
		m_Controls.USLoadTableWidget->insertRow(RowCount);
		m_Controls.USLoadTableWidget->setItem(RowCount, 0, new QTableWidgetItem(QgroupElement));
		m_Controls.USLoadTableWidget->setItem(RowCount, 1, new QTableWidgetItem(Qdiscription));
		m_Controls.USLoadTableWidget->setItem(RowCount, 2, new QTableWidgetItem(QdataFrameTimevector));


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
				//MITK_INFO << "ImageType is RGB";
				unsigned int dims = io->GetNumberOfDimensions();
				//MITK_INFO << "ImageDims is " << dims;

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

	mitk::DataNode* node = m_Controls.USReferenceSelectorCombox_3->GetSelectedNode();
	cout << "nodename: " << node->GetName() << endl;

	if (!node) return;

	this->ShowOnlySelectedNodes(node);

	this->GlobalReinit(true);
	mitk::RenderingManager::GetInstance()->RequestUpdateAll();
}

void USToolKitView::USLesionDataSelection(int index) {

	mitk::DataNode* node = m_Controls.USLesionSelectorCombox_2->GetSelectedNode();
	cout << "nodename: " << node->GetName() << endl;

	if (!node) return;

	this->ShowOnlySelectedNodes(node);

	this->GlobalReinit(true);
	mitk::RenderingManager::GetInstance()->RequestUpdateAll();
}



//bool USToolKitView::ShowSUVInfo(std::string USDicomPath)
//{
//	m_Controls.lineEditWeight->clear();
//	m_Controls.lineEditHeight->clear();
//	m_Controls.lineEditInjectDose->clear();
//	m_Controls.lineEditInjectTime->clear();
//	m_Controls.lineEditSeriesTime->clear();
//	m_Controls.lineEditSex->clear();
//	m_Controls.lineEditHalf->clear();
//	m_Controls.lineEditDecayCorrection->clear();
//
//
//	typedef itk::GDCMSeriesFileNames InputNamesGeneratorType;
//	//获取文件夹中所有dicom序列
//	InputNamesGeneratorType::Pointer inputNames = InputNamesGeneratorType::New();
//	inputNames->SetUseSeriesDetails(true);
//	inputNames->SetDirectory(USDicomPath);
//
//	itk::SerieUIDContainer seriesUIDs = inputNames->GetSeriesUIDs();
//
//	//获取文件名
//	typedef short PixelValueType;
//	typedef itk::Image< PixelValueType, 3 > VolumeType;
//	typedef itk::ImageSeriesReader< VolumeType > VolumeReaderType;
//	const VolumeReaderType::FileNamesContainer & filenames = inputNames->GetFileNames(seriesUIDs[0]);
//	std::string firstDicomFileName = filenames.front();
//
//	//加载文件
//	DcmFileFormat dfile;
//	OFCondition status = dfile.loadFile(OFFilename(firstDicomFileName.c_str()));
//	//MITK_INFO << firstDicomFileName.c_str();
//
//	if (status.bad())
//	{
//		return false;
//	}
//
//
//	//获取数据
//	DcmDataset *data = dfile.getDataset();
//
//	#define DCM_Modality   DcmTagKey(0x0008, 0x0060)
//	#define DCM_injectionTime  DcmTagKey(0x0018, 0x1072)
//	#define DCM_injectedDose  DcmTagKey(0x0018, 0x1074)
//	#define DCM_volumeUnits  DcmTagKey(0x0054, 0x1001)
//	#define DCM_height  DcmTagKey(0x0010, 0x1020)
//	#define DCM_weight  DcmTagKey(0x0010, 0x1030)
//	#define DCM_patientSex  DcmTagKey(0x0010, 0x0040)
//	#define DCM_radionuclideHalfLife  DcmTagKey(0x0018, 0x1075)
//	#define DCM_SeriesTimes DcmTagKey(0x0008, 0x0031)
//	#define DCM_DecayCorrection DcmTagKey(0x0054, 0x1102)
//
//	OFString Modality;
//	data->findAndGetOFString(DCM_Modality, Modality);
//	std::string dataModality = Modality.c_str();
//
//	OFString injectionTime;
//	data->findAndGetOFString(DCM_injectionTime, injectionTime, 0, OFTrue);
//	std::string dataInjectionTime = injectionTime.c_str();
//
//	OFString injectedDose;
//	data->findAndGetOFString(DCM_injectedDose, injectedDose, 0, OFTrue);
//	std::string dataInjectedDose = injectedDose.c_str();
//
//
//	OFString volumeUnits;
//	data->findAndGetOFString(DCM_volumeUnits, volumeUnits, 0, OFTrue);
//	std::string dataVolumeUnits = volumeUnits.c_str();
//
//	OFString height;
//	data->findAndGetOFString(DCM_height, height);
//	std::string dataHeight = height.c_str();
//
//	OFString weight;
//	data->findAndGetOFString(DCM_weight, weight);
//	std::string dataWeight = weight.c_str();
//
//	OFString patientSex;
//	data->findAndGetOFString(DCM_patientSex, patientSex);
//	std::string dataPatientSex = patientSex.c_str();
//
//	OFString radionuclideHalfLife;
//	data->findAndGetOFString(DCM_radionuclideHalfLife, radionuclideHalfLife, 0, OFTrue);
//	std::string dataRadionuclideHalfLife = radionuclideHalfLife.c_str();
//
//	OFString seriesTime;
//	data->findAndGetOFString(DCM_SeriesTimes, seriesTime);
//	std::string dataSeriesTime = seriesTime.c_str();
//
//	OFString DecayCorrection;
//	data->findAndGetOFString(DCM_DecayCorrection, DecayCorrection);
//	std::string dataDecayCorrection = DecayCorrection.c_str();
//
//
//	MITK_INFO << "output dicom tag info:";
//	MITK_INFO << "modality: " << dataModality;
//	MITK_INFO << "injectionTime: " << dataInjectionTime;
//	MITK_INFO << "injectedDose: " << dataInjectedDose;
//	MITK_INFO << "volumeUnits: " << dataVolumeUnits;
//	MITK_INFO << "height: " << dataHeight;
//	MITK_INFO << "weight: " << dataWeight;
//	MITK_INFO << "patientSex: " << dataPatientSex;
//	MITK_INFO << "radionuclideHalfLife: " << dataRadionuclideHalfLife;
//	MITK_INFO << "seriesTime: " << dataSeriesTime;
//
//	//注射时间格式转换
//	std::string tag;
//	std::string yearstr;
//	std::string monthstr;
//	std::string daystr;
//	std::string hourstr;
//	std::string minutestr;
//	std::string secondstr;
//	int len;
//	if (dataInjectionTime.c_str() != NULL && *(dataInjectionTime.c_str()) != '\0')
//	{
//		len = dataInjectionTime.length();
//		hourstr.clear();
//		minutestr.clear();
//		secondstr.clear();
//		if (len >= 2)
//		{
//			hourstr = dataInjectionTime.substr(0, 2);
//		}
//		else
//		{
//			hourstr = "00";
//		}
//		if (len >= 4)
//		{
//			minutestr = dataInjectionTime.substr(2, 2);
//		}
//		else
//		{
//			minutestr = "00";
//		}
//		if (len >= 6)
//		{
//			secondstr = dataInjectionTime.substr(4);
//		}
//		else
//		{
//			secondstr = "00";
//		}
//		tag.clear();
//		tag = hourstr.c_str();
//		tag += ":";
//		tag += minutestr.c_str();
//		tag += ":";
//		tag += secondstr.c_str();
//		dataInjectionTime = tag.c_str();
//	}
//	else {
//		dataInjectionTime = "";
//		MITK_WARN << " No injection time ";
//
//	}
//
//
//	if (dataVolumeUnits.c_str() != NULL && *(dataVolumeUnits.c_str()) != '\0')
//	{
//		//--- I think these are piled together. MBq ml... search for all.
//		std::string units = dataVolumeUnits.c_str();
//		if ((units.find("BQML") != std::string::npos) ||
//			(units.find("BQML") != std::string::npos))
//		{
//			dataVolumeUnits = "Bq";
//		}
//		else if ((units.find("MBq") != std::string::npos) ||
//			(units.find("MBQ") != std::string::npos))
//		{
//			dataVolumeUnits = "MBq";
//		}
//		else if ((units.find("kBq") != std::string::npos) ||
//			(units.find("kBQ") != std::string::npos) ||
//			(units.find("KBQ") != std::string::npos))
//		{
//			dataVolumeUnits = "kBq";
//		}
//		else if ((units.find("mBq") != std::string::npos) ||
//			(units.find("mBQ") != std::string::npos))
//		{
//			dataVolumeUnits = "mBq";
//		}
//		else if ((units.find("uBq") != std::string::npos) ||
//			(units.find("uBQ") != std::string::npos))
//		{
//			dataVolumeUnits = "uBq";
//		}
//		else if ((units.find("Bq") != std::string::npos) ||
//			(units.find("BQ") != std::string::npos))
//		{
//			dataVolumeUnits = "Bq";
//		}
//		else if ((units.find("MCi") != std::string::npos) ||
//			(units.find("MCI") != std::string::npos))
//		{
//			dataVolumeUnits = "MCi";
//		}
//		else if ((units.find("kCi") != std::string::npos) ||
//			(units.find("kCI") != std::string::npos) ||
//			(units.find("KCI") != std::string::npos))
//		{
//			dataVolumeUnits = "kCi";
//		}
//		else if ((units.find("mCi") != std::string::npos) ||
//			(units.find("mCI") != std::string::npos))
//		{
//			dataVolumeUnits = "mCi";
//		}
//		else if ((units.find("uCi") != std::string::npos) ||
//			(units.find("uCI") != std::string::npos))
//		{
//			dataVolumeUnits = "uCi";
//		}
//		else if ((units.find("Ci") != std::string::npos) ||
//			(units.find("CI") != std::string::npos))
//		{
//			dataVolumeUnits = "Ci";
//		}
//	}
//	else
//	{
//		dataVolumeUnits = "MBq";
//		MITK_WARN << " No radioactivity units, default is MBq ";
//	}
//
//	//--- SeriesTime
//	if (dataSeriesTime.c_str() != NULL && *(dataSeriesTime.c_str()) != '\0')
//	{
//		hourstr.clear();
//		minutestr.clear();
//		secondstr.clear();
//		len = dataSeriesTime.length();
//		if (len >= 2)
//		{
//			hourstr = dataSeriesTime.substr(0, 2);
//		}
//		else
//		{
//			hourstr = "00";
//		}
//		if (len >= 4)
//		{
//			minutestr = dataSeriesTime.substr(2, 2);
//		}
//		else
//		{
//			minutestr = "00";
//		}
//		if (len >= 6)
//		{
//			secondstr = dataSeriesTime.substr(4);
//		}
//		else
//		{
//			secondstr = "00";
//		}
//		tag.clear();
//		tag = hourstr.c_str();
//		tag += ":";
//		tag += minutestr.c_str();
//		tag += ":";
//		tag += secondstr.c_str();
//		dataSeriesTime = tag.c_str();
//	}
//	else
//	{
//		dataSeriesTime = "";
//		MITK_WARN << " No series time ";
//	}
//
//
//	//--- PatientSex
//	if (dataPatientSex.c_str() != NULL && *(dataPatientSex.c_str()) != '\0')
//	{
//		if (dataPatientSex != "M" && dataPatientSex != "F")
//		{
//			dataPatientSex = "";
//			MITK_WARN << " patient sex is not F or M";
//
//		}
//	}
//	else
//	{
//		dataPatientSex = "";
//		MITK_WARN << " No patient sex";
//
//	}
//
//	double dose;
//	if (injectedDose.c_str() != NULL && *(injectedDose.c_str()) != '\0')
//	{
//		dose = QString::fromStdString(injectedDose).toDouble();
//		MITK_INFO << "dataVolumeUnits.c_str() " << dataVolumeUnits.c_str();
//		MITK_INFO << "-----------------1" << dose;
//		dose = ConvertRadioactivityUnits(dose, dataVolumeUnits.c_str(), "kBq");  // kBq/mL
//		MITK_INFO << "-----------------" << dose;
//	}
//	else
//	{
//		dose = 0;
//		MITK_WARN << "NO inject dose,default is 0";
//	}
//	MITK_INFO << "Inject dose： " << dose;
//
//
//	double weight2;
//	if (dataWeight.c_str() != NULL && *(dataWeight.c_str()) != '\0') {
//		weight2 = QString::fromStdString(dataWeight).toDouble();
//		weight2 = ConvertWeightUnits(weight2, list.weightUnits.c_str(), "kg");
//
//		MITK_INFO << "weight units default is kg";
//	}
//	else
//	{
//		weight2 = 0.0;
//		MITK_WARN << "NO patient weight,default is 0 kg";
//	}
//	MITK_INFO << "weight： " << weight2;
//
//
//
//	double height2;
//	if (dataHeight.c_str() != NULL && *(dataHeight.c_str()) != '\0') {
//		height2 = QString::fromStdString(dataHeight).toDouble();
//		height2 = height2 * 100;//trans to cm
//		MITK_INFO << "height units default is cm";
//	}
//	else
//	{
//		height2 = 0.0;
//		MITK_WARN << "NO patient height,default is 0 cm";
//	}
//	MITK_INFO << "height： " << height2;
//
//
//	if (dataRadionuclideHalfLife.c_str() == NULL || *(dataRadionuclideHalfLife.c_str()) == '\0') {
//
//		dataRadionuclideHalfLife = "";
//		MITK_INFO << "NO RadionuclideHalfLife, default is 0";
//	}
//	MITK_INFO << "RadionuclideHalfLife： " << dataRadionuclideHalfLife;
//
//
//	if (dataDecayCorrection.c_str() == NULL || *(dataDecayCorrection.c_str()) == '\0') {
//
//		dataDecayCorrection = "";
//		MITK_INFO << "NO dataDecayCorrection, default is empty";
//	}
//	MITK_INFO << "dataDecayCorrection： " << dataDecayCorrection;
//
//
//	m_Controls.lineEditWeight->setText(QString::number(weight2));
//	m_Controls.lineEditHeight->setText(QString::number(height2));
//	m_Controls.lineEditInjectDose->setText(QString::number(dose));
//	m_Controls.lineEditInjectTime->setText(QString::fromStdString(dataInjectionTime));
//	m_Controls.lineEditSeriesTime->setText(QString::fromStdString(dataSeriesTime));
//	m_Controls.lineEditSex->setText(QString::fromStdString(dataPatientSex));
//	m_Controls.lineEditHalf->setText(QString::fromStdString(dataRadionuclideHalfLife));
//	m_Controls.lineEditDecayCorrection->setText(QString::fromStdString(dataDecayCorrection));
//
//	return true;
//}


void USToolKitView::USQuantitation()
{
	//get ROI node
	mitk::DataNode* referNode = m_Controls.USReferenceSelectorCombox_3->GetSelectedNode();
	mitk::DataNode* lesionNode = m_Controls.USLesionSelectorCombox_2->GetSelectedNode();
	//get original image node
	mitk::DataNode* datanode = m_Controls.USLoadSelectorCombox->GetSelectedNode();

	if ((!referNode) || (!lesionNode) || (!datanode)) return;

	mitk::Image::Pointer referRoiMitkImage = dynamic_cast<mitk::Image*>(referNode->GetData());
	mitk::Image::Pointer lesionRoiMitkImage = dynamic_cast<mitk::Image*>(lesionNode->GetData());
	mitk::Image::Pointer mitkInImage = dynamic_cast<mitk::Image*>(datanode->GetData());

	typedef itk::Image<double, 3> charImageType;

	std::string nodeName = datanode->GetName();
	MITK_INFO << nodeName;

	typedef itk::RGBPixel<unsigned char> PixelType;
	typedef itk::Image< PixelType, 3 > ItkRgbImageType;
	typedef mitk::ImageToItk< ItkRgbImageType > CasterType;
	CasterType::Pointer caster = CasterType::New();
	caster->SetInput(mitkInImage);
	caster->Update();
	ItkRgbImageType::Pointer itkInImage = caster->GetOutput();

	charImageType::Pointer referRoiItkImage = charImageType::New();
	mitk::CastToItkImage(referRoiMitkImage, referRoiItkImage);
	charImageType::Pointer lesionRoiItkImage = charImageType::New();
	mitk::CastToItkImage(lesionRoiMitkImage, lesionRoiItkImage);

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

	charImageType::Pointer EPItkImage = charImageType::New();
	EPItkImage->SetRegions(newRegion);
	EPItkImage->SetSpacing(newSpacing);
	EPItkImage->SetOrigin(itkInImage->GetOrigin());
	EPItkImage->SetDirection(itkInImage->GetDirection());
	EPItkImage->Allocate();

	charImageType::Pointer EPReferItkImage = charImageType::New();
	EPReferItkImage->SetRegions(newRegion);
	EPReferItkImage->SetSpacing(newSpacing);
	EPReferItkImage->SetOrigin(itkInImage->GetOrigin());
	EPReferItkImage->SetDirection(itkInImage->GetDirection());
	EPReferItkImage->Allocate();

	charImageType::Pointer EPLesionItkImage = charImageType::New();
	EPLesionItkImage->SetRegions(newRegion);
	EPLesionItkImage->SetSpacing(newSpacing);
	EPLesionItkImage->SetOrigin(itkInImage->GetOrigin());
	EPLesionItkImage->SetDirection(itkInImage->GetDirection());
	EPLesionItkImage->Allocate();

	int x = mitkInImage->GetDimensions()[0];
	int y = mitkInImage->GetDimensions()[1];
	int z = mitkInImage->GetDimensions()[2];
	int Vmax = 32767;
	int DR = 60;
	int RoiSlice;

	MITK_INFO << "convert before";
	//convert RGB to gray and calculate the EPdata
	ItkRgbImageType::IndexType pixelIndex;
	charImageType::IndexType RoiPixelIndex;
	typedef int RoiPixelType;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {

				pixelIndex[0] = i;
				pixelIndex[1] = j;
				pixelIndex[2] = k;
				RoiPixelIndex[0] = i;
				RoiPixelIndex[1] = j;
				RoiPixelIndex[2] = k;
				
				PixelType onePixel = itkInImage->GetPixel(pixelIndex);
				RoiPixelType lesionRoiPixel = lesionRoiItkImage->GetPixel(RoiPixelIndex);
				if (lesionRoiPixel> 0) RoiSlice = k;
				double greyPixel = (onePixel.GetRed() * 30 + onePixel.GetGreen() * 59 + onePixel.GetBlue() * 11 + 50) / 100.0;
				greyImage->SetPixel(pixelIndex, greyPixel);
				EPItkImage->SetPixel(pixelIndex, pow(Vmax, 2) * pow(10, ((greyPixel / 255.0 - 1) * DR) / 10));
			}
		}
	}
	MITK_INFO << "extract ROI";
	//extract ROI
	charImageType::IndexType EPPixelIndex;
	
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
				EPLesionItkImage->SetPixel(EPPixelIndex, EPItkPixel*lesionItkPixel);
			}
		}
	}

	//计算平均值
	std::vector<double> EPAverageValue;
	double RoiPixelCount=0;
	double sumOfSlice=0;
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
		RoiPixelCount = 0;
	}
	for (std::vector<double>::iterator it = EPAverageValue.begin(); it != EPAverageValue.end(); ++it)
	{
		MITK_INFO << *it;
	}
	// processing the time points
	QString Qtimepoints = m_Controls.USLoadTableWidget->item(0, 2)->text();
	std::string timepoints = Qtimepoints.toStdString();
	timepoints.push_back('\\');
	std::string tempstring;
	std::vector<double> tempGrid;
	double tempvalue;
	for (auto ch : timepoints)
	{
		if (ch == '\\') {
			tempGrid.push_back(stod(tempstring)/1000);
			tempstring.clear();
			continue;
		}
		tempstring.push_back(ch);
	}
	for (int i = 0; i < tempGrid.size(); i++)
	{
		if (i == 0)
		{
			tempGrid[i] = 0;
			continue;
		}
		tempGrid[i] = tempGrid[i-1] + tempGrid[i];
	}
	
	USCurveTIC(tempGrid, EPAverageValue);
	MITK_INFO << EPAverageValue.size();
	mitk::Image::Pointer greyMitkImage = mitk::Image::New();
	mitk::Image::Pointer EPMitkImage = mitk::Image::New();
	mitk::CastToMitkImage(greyImage, greyMitkImage);
	mitk::CastToMitkImage(EPItkImage, EPMitkImage);
	mitk::Image::Pointer EPLesionMitkImage = mitk::Image::New();
	mitk::CastToMitkImage(EPLesionItkImage, EPLesionMitkImage);

	mitk::DataNode::Pointer EPNode = mitk::DataNode::New();
	EPNode->SetData(EPLesionMitkImage);
	EPNode->SetName(nodeName + "_EPLesion");
	this->GetDataStorage()->Add(EPNode, datanode);

	// display the gray and EP image
	//mitk::DataNode::Pointer greyNode = mitk::DataNode::New();
	//greyNode->SetData(greyMitkImage);
	//greyNode->SetName(nodeName + "_grey");
	//this->GetDataStorage()->Add(greyNode, node);

	//mitk::DataNode::Pointer EPNode = mitk::DataNode::New();
	//EPNode->SetData(EPMitkImage);
	//EPNode->SetName(nodeName + "_EP");
	//this->GetDataStorage()->Add(EPNode, node);

	MITK_INFO << "Quantitation done";
}


void USToolKitView::USCurveTIC(std::vector<double> tempGrid, std::vector<double> statisticsMean)
{
	m_Controls.widgetPlot->Clear();

	std::string xAxis = "Time[s]";
	std::string yAxis = "Echo power";
	std::string plotTitle = "TIC Plot";

	m_Controls.widgetPlot->SetAxisTitle(QwtPlot::xBottom, xAxis.c_str());
	m_Controls.widgetPlot->SetAxisTitle(QwtPlot::yLeft, yAxis.c_str());
	m_Controls.widgetPlot->SetPlotTitle(plotTitle.c_str());

	unsigned int curveId = this->m_Controls.widgetPlot->InsertCurve("TIC");

	QPen pen(Qt::SolidLine);
	pen.setWidth(2);
	pen.setColor(Qt::red);
	m_Controls.widgetPlot->SetCurveData(curveId, tempGrid, statisticsMean);
	m_Controls.widgetPlot->SetCurvePen(curveId, pen);
	m_Controls.widgetPlot->SetCurveStyle(curveId, QwtPlotCurve::Lines);
	m_Controls.widgetPlot->Replot();


	//this->SetDataOverlayShow();
	this->GlobalReinit(true);

}


/*
void USToolKitView::USExtractChannel()
{
	// if user selected  the data
	mitk::DataNode* node = m_Controls.USPreprocessDataSelectionComBox->GetSelectedNode();
	if (!node)
		return;

	typedef itk::Image< unsigned char, 3 > charimageType;

	mitk::DataStorage::SetOfObjects::ConstPointer _NodeSets = m_Controls.USPreprocessDataSelectionComBox->GetNodes();
	for (mitk::DataStorage::SetOfObjects::ConstIterator iter2 = _NodeSets->Begin(); iter2 != _NodeSets->End(); ++iter2)
	{
		mitk::DataNode* node = const_cast<mitk::DataNode*>(iter2->Value().GetPointer());
		if (!node)
			continue;

		mitk::Image::Pointer mitkInImage = dynamic_cast<mitk::Image*>(node->GetData());
		if (!mitkInImage)
			continue;

		std::string nodeName = node->GetName();
		MITK_INFO << "name: " << nodeName;

		//mitk RGB×ªITK RGBÍ¼Ïñ
		typedef itk::RGBPixel<unsigned char> PixelType;
		typedef itk::Image< PixelType, 3 > ItkRgbImageType;
		typedef mitk::ImageToItk< ItkRgbImageType > CasterType;
		CasterType::Pointer caster = CasterType::New();
		caster->SetInput(mitkInImage);
		caster->Update();
		ItkRgbImageType::Pointer itkInImage = caster->GetOutput();

		charimageType::RegionType newRegion;
		charimageType::SizeType newSize = itkInImage->GetLargestPossibleRegion().GetSize();
		newRegion.SetSize(itkInImage->GetLargestPossibleRegion().GetSize());
		newRegion.SetIndex(itkInImage->GetLargestPossibleRegion().GetIndex());


		charimageType::SpacingType newSpacing;
		newSpacing[0] = itkInImage->GetSpacing()[0];
		newSpacing[1] = itkInImage->GetSpacing()[1];
		newSpacing[2] = itkInImage->GetSpacing()[2];


		charimageType::Pointer redImage = charimageType::New();
		redImage->SetRegions(newRegion);
		redImage->SetSpacing(newSpacing);
		redImage->SetOrigin(itkInImage->GetOrigin());
		redImage->SetDirection(itkInImage->GetDirection());
		redImage->Allocate();

		charimageType::Pointer blueImage = charimageType::New();
		blueImage->SetRegions(newRegion);
		blueImage->SetSpacing(newSpacing);
		blueImage->SetOrigin(itkInImage->GetOrigin());
		blueImage->SetDirection(itkInImage->GetDirection());
		blueImage->Allocate();

		charimageType::Pointer greenImage = charimageType::New();
		greenImage->SetRegions(newRegion);
		greenImage->SetSpacing(newSpacing);
		greenImage->SetOrigin(itkInImage->GetOrigin());
		greenImage->SetDirection(itkInImage->GetDirection());
		greenImage->Allocate();

		charimageType::Pointer greyImage = charimageType::New();
		greyImage->SetRegions(newRegion);
		greyImage->SetSpacing(newSpacing);
		greyImage->SetOrigin(itkInImage->GetOrigin());
		greyImage->SetDirection(itkInImage->GetDirection());
		greyImage->Allocate();


		int x = mitkInImage->GetDimensions()[0];
		int y = mitkInImage->GetDimensions()[1];
		int z = mitkInImage->GetDimensions()[2];

		//·Ö±ðÌáÈ¡RGB£¬ÒÔ¼°ºÏ³É»Ò¶ÈÍ¼Ïñ
		ItkRgbImageType::IndexType pixelIndex;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				for (int k = 0; k < z; k++) {

					pixelIndex[0] = i;
					pixelIndex[1] = j;
					pixelIndex[2] = k;
					PixelType onePixel = itkInImage->GetPixel(pixelIndex);

					redImage->SetPixel(pixelIndex, onePixel.GetRed());
					greenImage->SetPixel(pixelIndex, onePixel.GetGreen());
					blueImage->SetPixel(pixelIndex, onePixel.GetBlue());
					greyImage->SetPixel(pixelIndex, (onePixel.GetRed() * 30 + onePixel.GetGreen() * 59 + onePixel.GetBlue() * 11 + 50) / 100);
				}
			}
		}

		mitk::Image::Pointer bImage = mitk::Image::New();
		mitk::Image::Pointer rImage = mitk::Image::New();
		mitk::Image::Pointer gImage = mitk::Image::New();
		mitk::Image::Pointer greyMitkImage = mitk::Image::New();

		mitk::CastToMitkImage(redImage, rImage);
		mitk::CastToMitkImage(greenImage, gImage);
		mitk::CastToMitkImage(blueImage, bImage);
		mitk::CastToMitkImage(greyImage, greyMitkImage);


		mitk::DataNode::Pointer bNode = mitk::DataNode::New();
		bNode->SetData(bImage);
		bNode->SetName(nodeName+"_blue");
		this->GetDataStorage()->Add(bNode,node);


		mitk::DataNode::Pointer rNode = mitk::DataNode::New();
		rNode->SetData(rImage);
		rNode->SetName(nodeName+"_red");
		this->GetDataStorage()->Add(rNode, node);

		mitk::DataNode::Pointer gNode = mitk::DataNode::New();
		gNode->SetData(gImage);
		gNode->SetName(nodeName + "_green");
		this->GetDataStorage()->Add(gNode,node);

		mitk::DataNode::Pointer greyNode = mitk::DataNode::New();
		greyNode->SetData(greyMitkImage);
		greyNode->SetName(nodeName+"_grey");
		this->GetDataStorage()->Add(greyNode, node);


	}
	
}
*/


void USToolKitView::ConvertToEchoPower()
{

}

void USToolKitView::USRGBConvertGray() 
{
	//mitk::DataNode* node = m_Controls.USPreprocessDataSelectionComBox->GetSelectedNode();
	//if (!node)
	//	return;

	//mitk::Image::Pointer image = dynamic_cast<mitk::Image*>(node->GetData());
	//if (!image)
	//	return;

	//int x = image->GetDimensions()[0];
	//int y = image->GetDimensions()[1];
	//int z = image->GetDimensions()[2];

	//MITK_INFO << "dimensions: " << x << " " << y << " " << z;

	//cv::Mat image2(y, x, CV_16U, image->GetData());
	////mitk::ImageToOpenCVImageFilter::Pointer cvFilter = mitk::ImageToOpenCVImageFilter::New();
	////cvFilter->SetImage(image);
	////cv::Mat cvImage = cvFilter->GetOpenCVMat();

	//mitk::ConvertGrayscaleOpenCVImageFilter::Pointer cvGrayFilter = mitk::ConvertGrayscaleOpenCVImageFilter::New();
	//cvGrayFilter->FilterImage(image2);

	//mitk::OpenCVToMitkImageFilter::Pointer mitkGrayImageFromCV = mitk::OpenCVToMitkImageFilter::New();
	//mitkGrayImageFromCV->SetOpenCVMat(image2);
	//mitk::Image::Pointer convertImage = mitkGrayImageFromCV->GetOutput();

	//mitk::DataNode::Pointer newNode = mitk::DataNode::New();
	//newNode->SetData(convertImage);
	//newNode->SetName("test");

	//this->GetDataStorage()->Add(newNode);
	
}
