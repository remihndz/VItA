#	Dependencies handling
include (ExternalProject)

set (DEPENDENCIES_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR})
set (VTK_INCLUDE_DIR ${DEPENDENCIES_INSTALL_DIR}/include/vtk-8.1)
set (VTK_LIB_DIR ${DEPENDENCIES_INSTALL_DIR}/lib)
set (DEPENDENCIES_CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_INSTALL_DIR}
    -DPACKAGE_CONFIG_DIR=cmake
	-DCMAKE_PREFIX_PATH=${DEPENDENCIES_INSTALL_DIR}/cmake
    -DCMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}
    -DCMAKE_BUILD_TYPE=Release
    -DCMAKE_NO_SYSTEM_FROM_IMPORTED=YES
    -DCMAKE_POSITION_INDEPENDENT_CODE=YES # -fPIC flag - always enable
    )
set (DEPENDENCIES)
    
list (APPEND DEPENDENCIES csim)
ExternalProject_Add (vtk
  URL https://www.vtk.org/files/release/8.1/VTK-8.1.0.tar.gz

  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  BUILD_COMMAND ${CMAKE_COMMAND} --build .

  CMAKE_ARGS ${DEPENDENCIES_CMAKE_ARGS} -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF -DBUILD_DOCUMENTATION=OFF
)  

set(VTK_LIBRARIES
		vtkCommonCore-8.1
		vtkCommonDataModel-8.1
		vtkCommonExecutionModel-8.1
		vtkFiltersFlowPaths-8.1
		vtkFiltersModeling-8.1
		vtkIOCore-8.1
		vtkIOLegacy-8.1
		vtkIOXML-8.1
		vtkIOGeometry-8.1
	)
