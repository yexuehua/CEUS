project(US_ToolKit)

mitk_create_plugin(
  EXPORT_DIRECTIVE US_ToolKit_EXPORT
  EXPORTED_INCLUDE_SUFFIXES src
  MODULE_DEPENDS  MitkQtWidgets MitkQtWidgetsExt MitkPlanarFigure MitkBoundingShape MitkMultilabel MitkSegmentationUI MitkSegmentation MitkImageStatistics  MitkModelFit MitkModelFitUI MitkPharmacokinetics MitkPharmacokineticsUI
  PACKAGE_DEPENDS CTK|CTKCore ITK DCMTK
)


INCLUDE_DIRECTORIES(


	${MITK_SOURCE_DIR}/Modules/SegmentationUI/Qmitk
	${MITK_SOURCE_DIR}/Modules/Segmentation/Controllers
	${MITK_SOURCE_DIR}/Modules/SurfaceInterpolation
	${MITK_SOURCE_DIR}/Modules/Segmentation/Interactions
	${MITK_SOURCE_DIR}/Modules/BoundingShape/include
	${MITK_SOURCE_DIR}/Modules/Segmentation/Algorithms
	${MITK_SOURCE_DIR}/Modules/Segmentation/SegmentationUtilities/MorphologicalOperations
	${MITK_SOURCE_DIR}/Modules/Segmentation/DataManagement
	${MITK_SOURCE_DIR}/Modules/PharmacokineticsUI/Qmitk
	${MITK_SOURCE_DIR}/Modules/PharmacokineticsUI/include
	${MITK_SOURCE_DIR}/Modules/ModelFitUI/Qmitk
	${MITK_SOURCE_DIR}/Modules/Pharmacokinetics/include
	${MITK_SOURCE_DIR}/Modules/ImageStatistics

	${MITK_SOURCE_DIR}/Plugins/org.mitk.gui.qt.multilabelsegmentation/src
	${MITK_SOURCE_DIR}/Plugins/org.mitk.gui.qt.multilabelsegmentation/src/internal
	${MITK_SOURCE_DIR}/Plugins/org.mitk.gui.qt.multilabelsegmentation/src/internal

	${MITK_BINARY_DIR}/../MITK-build/Modules/Pharmacokinetics
	${MITK_BINARY_DIR}/../MITK-build/Modules/SegmentationUI
	${MITK_BINARY_DIR}/../MITK-build/Modules/Segmentation
	${MITK_BINARY_DIR}/../MITK-build/Modules/SurfaceInterpolation
	${MITK_BINARY_DIR}/../MITK-build/Modules/BoundingShape
	${MITK_BINARY_DIR}/../ep/src/Eigen
	${MITK_BINARY_DIR}/../ep/src/ITK/Modules/IO/DCMTK/include
	${MITK_BINARY_DIR}/../ep/src/ITK-build/Modules/Core/Common
	
	
	${PROJECT_SOURCE_DIR}/src/internal
)


