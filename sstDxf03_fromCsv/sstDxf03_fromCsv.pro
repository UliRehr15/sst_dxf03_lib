TEMPLATE	  = app
CONFIG	 	 += warn_on
CONFIG       -= qt
CONFIG       -= windows
CONFIG += c++11


# CONFIG       -= debug  # RELEASE ist aktiv
CONFIG       -= release  # DEBUG ist aktiv

INCLUDEPATH +=  ../../dxflib/Header
INCLUDEPATH +=  ../../sstLibreCAD2Lib/Header
INCLUDEPATH +=  ../../sst_str01_lib/Header
INCLUDEPATH +=  ../../sstMath01Lib/Header
INCLUDEPATH +=  ../../sst_misc01_lib/Header
INCLUDEPATH +=  ../../sst_rec04_lib/Header
INCLUDEPATH +=  ../Header

debug{
  LIBS        += ../../libs/libsst_dxf03_lib_d.a
  LIBS        += ../../libs/libsst_rec04_lib_d.a
  LIBS        += ../../libs/libsst_misc01_lib_d.a
  LIBS        += ../../libs/libsstMath01Lib_d.a
  LIBS        += ../../libs/libsst_str01_lib_d.a
  LIBS        += ../../libs/libsstLibreCAD2Lib_d.a
  LIBS        += ../../libs/libdxflib_d.a
}

release{

  win32-g++:QMAKE_LFLAGS += -static
  win32-g++:QMAKE_LFLAGS -= -mthreads
  win32-g++:QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
  win32-g++:QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads


  LIBS        += ../../libs/libsst_dxf03_lib_r.a
  LIBS        += ../../libs/libsst_rec04_lib_r.a
  LIBS        += ../../libs/libsst_misc01_lib_r.a
  LIBS        += ../../libs/libsst_str01_lib_r.a
  LIBS        += ../../libs/libsstLibreCAD2Lib_r.a
  LIBS        += ../../libs/libdxflib_r.a
}

HEADERS += \
    sstDxf03_fromCsv.h

SOURCES    += sstDxf03_fromCsv.cpp
#    sstDxf02Database.cpp \
#    sstDxf02Write.cpp \
#    sstDxf02TypMain.cpp \
#    sstDxf02EntityType.cpp

TARGET	  	= sstDxf03_fromCsv

