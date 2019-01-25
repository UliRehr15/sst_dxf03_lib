TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows
CONFIG += c++11


# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH += ../dxflib/src
INCLUDEPATH += ../sstLibreCAD2Lib/Header
INCLUDEPATH += ../sst_str01_lib/Header
INCLUDEPATH += ../sstMath01Lib/Header
INCLUDEPATH += ../sst_misc01_lib/Header
INCLUDEPATH += ../sst_rec04_lib/Header
INCLUDEPATH += ./Header

HEADERS		+= ./Header/sstDxf03Lib.h \
          += sstDxf03LibInt.h

SOURCES		+=  \
    ./Entities/sstDxf03Arc.cpp \
    ./Entities/sstDxf03Circle.cpp \
    ./Entities/sstDxf03Hatch.cpp \
    ./Entities/sstDxf03HatchEdge.cpp \
    ./Entities/sstDxf03HatchLoop.cpp \
    ./Entities/sstDxf03Insert.cpp \
    ./Entities/sstDxf03MText.cpp \
    ./Entities/sstDxf03Polyline.cpp \
    ./Entities/sstDxf03Text.cpp \
    ./Entities/sstDxf03Vertex.cpp \
    ./Entities/sstDxf03Point.cpp \
    ./Entities/sstDxf03Line.cpp \
    ./Tables/sstDxf03LType.cpp \
    sstDxf03Write.cpp \
    sstDxf03Read.cpp \
    sstDxf03Main.cpp \
    sstDxf03Layer.cpp \
    sstDxf03Database.cpp \
    sstDxf03EntityType.cpp \
    sstDxf03Base.cpp \
    sstDxf03Block.cpp \
    sstDxf03Lib.cpp \
    Entities/sstDxf03Trace.cpp

OTHER_FILES += README.md \
               sstDxf03Type.def

debug{
  TARGET		= sst_dxf03_lib_d
}
release{
  TARGET		= sst_dxf03_lib_r
}

DESTDIR     = ../libs

DISTFILES += \
    sstDxf03Lib.odt

