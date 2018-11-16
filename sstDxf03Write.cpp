/**********************************************************************
 *
 * sstDxf03Lib - sst dxf library
 * Hosted on github
 *
 * Copyright (C) 2016 Uli Rehr
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file gpl-2.0.txt included in the
 * packaging of this file.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * This copyright notice MUST APPEAR in all copies of the script!
 *
**********************************************************************/
// sstDxf03Write.cpp    16.05.18  Re.    05.04.16  Re.
//
// Several functions for dxf output
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <list>

#include <dl_dxf.h>
#include <dl_creationadapter.h>

#include <rs_vector.h>

#include <sstStr01Lib.h>
#include <sstMath01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf03Lib.h>

#include "sstDxf03LibInt.h"

//=============================================================================
sstDxf03WriteCls::sstDxf03WriteCls (sstDxf03DatabaseCls *oDxfDb, sstMisc01PrtFilCls *oTmpPrt)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  // if ( iKey != 0) return -1;

  // *dxf = new DL_Dxf();
  this->dxf = new DL_Dxf();

  this->poPrt = oTmpPrt;

  this->dw = NULL;

  this->poDxfDb = oDxfDb;


//  DL_Codes::version exportVersion = DL_Codes::AC1015;
//  // *dw = (*dxf)->out("myfile.dxf", exportVersion);
//  this->dw = this->dxf->out("myfile2.dxf", exportVersion);
//  if (this->dw == NULL) {
//      printf("Cannot open file 'myfile.dxf'
//             for writing.");
//      // abort function e.g. with return
//             iRet = -1;
//  }

  // this->oDxfDB = oTmpDxfDB;

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  // return iRet;
}
//=============================================================================
sstDxf03WriteCls::~sstDxf03WriteCls ()
//-----------------------------------------------------------------------------
{
  //--- Write buffer to dxf file and close
  if (this->dw != NULL)
  {
    this->dw->dxfEOF();
    this->dw->close();
    delete this->dw;
  }
  delete this->dxf;

}
//=============================================================================
int sstDxf03WriteCls::OpenNewDxfFile (int  iKey, std::string oDxfFilNam)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  DL_Codes::version exportVersion = DL_Codes::AC1015;
  this->dw = this->dxf->out(oDxfFilNam.c_str(), exportVersion);
  if (this->dw == NULL) {
      printf("Cannot open file 'myfile.dxf' \
             for writing.");
      // abort function e.g. with return
             iStat = -1;
  }
  return iStat;
}
//=============================================================================
int sstDxf03WriteCls::WrtSecHeader (int         iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Write Header-------------------------------------------------------------

  this->dxf->writeHeader(*this->dw);
  // int variable:
  this->dw->dxfString(9, "$INSUNITS");
  this->dw->dxfInt(70, 4);
  // real (double, float) variable:
  this->dw->dxfString(9, "$DIMEXE");
  this->dw->dxfReal(40, 1.25);
  // string variable:
  this->dw->dxfString(9, "$TEXTSTYLE");
  this->dw->dxfString(7, "Standard");
  // vector variable:
  this->dw->dxfString(9, "$LIMMIN");
  this->dw->dxfReal(10, 0.0);
  this->dw->dxfReal(20, 0.0);
  this->dw->sectionEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstDxf03WriteCls::WrtSecLayers (int         iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Section Tables -------------------------------------------------------------

  sstDxf03FncLayCls *oLocSstFncLay = NULL;            /**< layer sst table object */
  oLocSstFncLay = this->poDxfDb->getSstFncLay();
  sstDxf03FncLTypeCls *oLocSstFncLType = NULL;        /**< ltype sst table object */
  oLocSstFncLType = this->poDxfDb->getSstFncLType();

  // set number of defined layers to dxflib
  dREC04RECNUMTYP dNumLayers = oLocSstFncLay->count();
  this->dw->tableLayers((int) dNumLayers);

  sstDxf03TypLayCls oLayRec;
  sstDxf03TypLTypeCls oLTypeRec;

  for (dREC04RECNUMTYP dd=1; dd <= dNumLayers; dd++)
  {
    iStat = oLocSstFncLay->Read(0,dd,&oLayRec);
    iStat = oLocSstFncLType->Read(0,oLayRec.getLinetypeID(),&oLTypeRec);

    double dLinetypeScale = 1.0;
    this->dxf->writeLayer(*this->dw,
                   DL_LayerData(oLayRec.getName(), 0), /** Layer flags. (1 = frozen, 2 = frozen by default, 4 = locked) */
                   DL_Attributes(
                       std::string(""),
                       oLayRec.getColor(),
                       oLayRec.getWidth(),
                       oLTypeRec.getName(), dLinetypeScale));
  }

  this->dw->tableEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstDxf03WriteCls::WrtSecBlocks (int         iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf03FncMainCls *oLocSstFncMain = NULL;              /**< main recmem object */
  sstDxf03TypMainCls oMainRec;
  oLocSstFncMain = this->poDxfDb->getSstFncMain();

  sstDxf03FncBlkCls *oLocSstFncBlk = NULL;              /**< Block recmem object */
  sstDxf03TypBlkCls oBlkRec;
  oLocSstFncBlk = this->poDxfDb->getSstFncBlk();

  sstDxf03FncLTypeCls *oLocSstFncLType = NULL;              /**< LType Table object */
  sstDxf03TypLTypeCls oLTypeRec;
  oLocSstFncLType = this->poDxfDb->getSstFncLType();

  // start Section Blocks
  this->dw->sectionBlocks();

  // loop over all defined blocks
  dREC04RECNUMTYP dNumBlocks = oLocSstFncBlk->count();

  if (dNumBlocks == 0)  // no blocks defined, write standard blocks and return
  {
    this->dxf->writeBlock(*this->dw,
                   DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
    this->dxf->writeEndBlock(*this->dw, "*Model_Space");

    this->dxf->writeBlock(*this->dw,
                   DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
    this->dxf->writeEndBlock(*this->dw, "*Paper_Space");

    this->dw->sectionEnd();
    return 0;
  }

  for (dREC04RECNUMTYP ii=1; ii <= dNumBlocks; ii++)
  {
    iStat = oLocSstFncBlk->Read( 0, ii, &oBlkRec);
    dxf->writeBlock(*dw,
                   DL_BlockData(oBlkRec.getName(), 0, 0.0, 0.0, 0.0));


    // loop over all record in main table
    // if part of actual block, write to actual block

    // dREC04RECNUMTYP dActBlockID = 0;
    dREC04RECNUMTYP dNumMains = oLocSstFncMain->count();
    for (dREC04RECNUMTYP ll=1; ll <= dNumMains; ll++)
    {
      iStat = oLocSstFncMain->Read( 0, ll, &oMainRec);
      std::string oSectStr = oMainRec.getSectString();
      iStat = oSectStr.compare("B");
      if(iStat == 0 && ii == oMainRec.getLayBlockID())
      {  // this element is part of the actual block

        switch (oMainRec.getEntityType())
        {
        case RS2::EntityArc:
        {
        sstDxf03FncArcCls *oLocSstFncArc = NULL;              /**< Arc recmem object */
        sstDxf03TypArcCls oArcRec;
        oLocSstFncArc = this->poDxfDb->getSstFncArc();

        iStat = oLocSstFncArc->Read(0,oMainRec.getTypeID(),&oArcRec);
          DL_ArcData oDL_Arc( 0.0,0.0,0.0,
                              1.0,        // Radius
                              0.0,0.0);   // Angle1, angle2
          // Write arc parameter to dxflib arc
          oArcRec.WritToDL(&oDL_Arc);

          DL_Attributes oAttributes;  // Dxflib Attributes
          oArcRec.BaseWritToDL(&oAttributes);
          oAttributes.setLayer(oBlkRec.getName());
          oAttributes.setLinetype("BYBLOCK");

          // write next insert into dxf file
          this->dxf->writeArc(  *this->dw, oDL_Arc, oAttributes);

        }
        break;
        case RS2::EntityCircle:
        {
        sstDxf03FncCircleCls *oLocSstFncCircle = NULL;              /**< Arc recmem object */
        sstDxf03TypCircleCls oCircleRec;
        oLocSstFncCircle = this->poDxfDb->getSstFncCircle();

        iStat = oLocSstFncCircle->Read(0,oMainRec.getTypeID(),&oCircleRec);
        DL_CircleData oDL_Circle(0.0,0.0,0.0,0.0);
          // Write arc parameter to dxflib arc
          oCircleRec.WritToDL(&oDL_Circle);

          DL_Attributes oAttributes;  // Dxflib Attributes
          oCircleRec.BaseWritToDL(&oAttributes);
          oAttributes.setLayer(oBlkRec.getName());
          oAttributes.setLinetype("BYBLOCK");

          // write next insert into dxf file
          this->dxf->writeCircle( *this->dw, oDL_Circle, oAttributes);

        }
        break;
        case RS2::EntityMText:
        {
        sstDxf03FncMTextCls *oLocSstFncMText = NULL;              /**< Arc recmem object */
        sstDxf03TypMTextCls oMTextRec;
        oLocSstFncMText = this->poDxfDb->getSstFncMText();

        iStat = oLocSstFncMText->Read(0,oMainRec.getTypeID(),&oMTextRec);
        DL_MTextData oDL_MText(0,0,0,0,0,0,0,0,0,0,0,0,"","",0);
          // Write arc parameter to dxflib arc
          oMTextRec.WritToDL(&oDL_MText);

          DL_Attributes oAttributes;  // Dxflib Attributes
          oMTextRec.BaseWritToDL(&oAttributes);
          oAttributes.setLayer(oBlkRec.getName());
          oAttributes.setLinetype("BYBLOCK");

          // write next insert into dxf file
          this->dxf->writeMText(  *this->dw, oDL_MText, oAttributes);

        }
        break;
        case RS2::EntityText:
        {
        sstDxf03FncTextCls *oLocSstFncText = NULL;              /**< Arc recmem object */
        sstDxf03TypTextCls oTextRec;
        oLocSstFncText = this->poDxfDb->getSstFncText();

        iStat = oLocSstFncText->Read(0,oMainRec.getTypeID(),&oTextRec);
        DL_TextData oDL_Text(0,0,0,0,0,0,0,0,0,0,0,"","",0);
          // Write arc parameter to dxflib arc
          oTextRec.WritToDL(&oDL_Text);

          DL_Attributes oAttributes;  // Dxflib Attributes
          oTextRec.BaseWritToDL(&oAttributes);
          oAttributes.setLayer(oBlkRec.getName());
          oAttributes.setLinetype("BYBLOCK");

          // write next insert into dxf file
          this->dxf->writeText(  *this->dw, oDL_Text, oAttributes);

        }
        break;
        case RS2::EntityPoint:
        {
        sstDxf03FncPointCls *oLocSstFncPoint = NULL;              /**< Arc recmem object */
        sstDxf03TypPointCls oPointRec;
        oLocSstFncPoint = this->poDxfDb->getSstFncPoint();

        iStat = oLocSstFncPoint->Read(0,oMainRec.getTypeID(),&oPointRec);
        // DL_PointData oDL_Point(0,0,0,0,0,0,0,0,0,0,0,"","",0);
        DL_PointData oDL_Point;
          // Write arc parameter to dxflib arc
          oPointRec.WritToDL(&oDL_Point);

          DL_Attributes oAttributes;  // Dxflib Attributes
          oPointRec.BaseWritToDL(&oAttributes);
          oAttributes.setLayer(oBlkRec.getName());
          oAttributes.setLinetype("BYBLOCK");

          // write next insert into dxf file
          this->dxf->writePoint(  *this->dw, oDL_Point, oAttributes);

        }
        break;
        case RS2::EntityLine:
        {
        sstDxf03FncLineCls *oLocSstFncLine = NULL;              /**< Arc recmem object */
        sstDxf03TypLineCls oLineRec;
        oLocSstFncLine = this->poDxfDb->getSstFncLine();

        iStat = oLocSstFncLine->Read(0,oMainRec.getTypeID(),&oLineRec);
        // DL_LineData oDL_Line(0,0,0,0,0,0,0,0,0,0,0,"","",0);
        DL_LineData oDL_Line(0,0,0,0,0,0);
          // Write arc parameter to dxflib arc
          oLineRec.WritToDL(&oDL_Line);

          DL_Attributes oAttributes;  // Dxflib Attributes
          oLineRec.BaseWritToDL(&oAttributes);
          oAttributes.setLayer(oBlkRec.getName());
          oAttributes.setLinetype("BYBLOCK");

          // write next insert into dxf file
          this->dxf->writeLine(  *this->dw, oDL_Line, oAttributes);

        }
        break;
        case RS2::EntityPolyline:
        {
          sstDxf03TypPolylineCls oPolylineRec;
          sstDxf03FncPolylineCls *oLocSstFncPolyline = NULL;
          oLocSstFncPolyline = this->poDxfDb->getSstFncPolyline();

          // if new entity-type, then write open polyline or hatch and close
          iStat = this->WriteOpenEntities(0);

          iStat = oLocSstFncPolyline->Read(0,oMainRec.getTypeID(),&oPolylineRec);
          assert(iStat == 0);

          // write record data to dxflib object
          DL_PolylineData oDL_Polyline(0,0,0,0);
          oPolylineRec.WritToDL(&oDL_Polyline);

          iStat = oLocSstFncLType->Read ( 0, oPolylineRec.getLinetypeID(), &oLTypeRec);
          assert(iStat == 0);

          DL_Attributes oAttributes;  // Dxflib Attributes
          oPolylineRec.BaseWritToDL(&oAttributes);
  //        oAttributes.setColor(oPolylineRec.getColor());
  //        oAttributes.setColor24(oPolylineRec.getColor24());
  //        oAttributes.setHandle(oPolylineRec.getHandle());
          oAttributes.setLayer(oBlkRec.getName());
          oAttributes.setLinetype(oLTypeRec.getName());
  //        oAttributes.setWidth(oPolylineRec.getWidth());

          if ( strncmp( oLTypeRec.getName(), "BYBLOCK", dSSTDXF03LTYPENAMELEN) == 0)
          {  // LineType / width by layer

            // Read linetype from layer
            iStat = oLocSstFncLType->Read ( 0, oBlkRec.getLinetypeID(), &oLTypeRec);
            assert(iStat == 0);

            oAttributes.setLinetype(oLTypeRec.getName());

          }

          if ( oPolylineRec.getColor() == 256)
          {  // Color by Layer
            oAttributes.setColor(oBlkRec.getColor());
          }

          if ( oPolylineRec.getWidth() == -1)
          {  // Color by Layer
            oAttributes.setWidth(oBlkRec.getWidth());
          }

          // write next insert into dxf file
          this->dxf->writePolyline(  *this->dw, oDL_Polyline, oAttributes);

          this->poDxfDb->setActEntType(oMainRec.getEntityType());
          this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());
        }
        break;
        case RS2::EntityVertex:
        {
          sstDxf03FncVertexCls *oLocSstFncVertex = NULL;
          oLocSstFncVertex = this->poDxfDb->getSstFncVertex();

          sstDxf03TypVertexCls oVertexRec;
          DL_VertexData oDL_Vertex(0.0,0.0,0.0,0.0);

          iStat = oLocSstFncVertex->Read(0,oMainRec.getTypeID(),&oVertexRec);
          assert(iStat == 0);

          // write record data to dxflib object
          oVertexRec.WritToDL(&oDL_Vertex);

          // write next insert into dxf file
          this->dxf->writeVertex(  *this->dw,
                                    oDL_Vertex);
        }
        break;
        case RS2::EntityHatch:
        {
          sstDxf03FncHatchCls *oLocSstFncHatch = NULL;
          oLocSstFncHatch = this->poDxfDb->getSstFncHatch();

          sstDxf03TypHatchCls oHatchRec;
          DL_HatchData oDL_Hatch;

          iStat = oLocSstFncHatch->Read(0,oMainRec.getTypeID(),&oHatchRec);
          assert(iStat == 0);

          iStat = oLocSstFncLType->Read ( 0, oHatchRec.getLinetypeID(), &oLTypeRec);
          assert(iStat == 0);

          DL_Attributes oDL_Attributes;
          oDL_Attributes.setLayer(oBlkRec.getName());
          oDL_Attributes.setColor( oHatchRec.getColor());
          oDL_Attributes.setWidth( oHatchRec.getWidth());
          oDL_Attributes.setHandle( oHatchRec.getHandle());
          oDL_Attributes.setLinetype( oLTypeRec.getName());


          // write record data to dxflib object
          oHatchRec.WritToDL(&oDL_Hatch);
          oDL_Hatch.pattern = "SOLID";

          // write next Hatch into dxf file
          this->dxf->writeHatch1( *this->dw,
                                    oDL_Hatch, oDL_Attributes);
        }
        break;
        case RS2::EntityHatchLoop:
        {
          sstDxf03FncHatchLoopCls *oLocSstFncHatchLoop = NULL;
          oLocSstFncHatchLoop = this->poDxfDb->getSstFncHatchLoop();

          sstDxf03TypHatchLoopCls oHatchLoopRec;
          DL_HatchLoopData oDL_HatchLoop;

          iStat = oLocSstFncHatchLoop->Read(0,oMainRec.getTypeID(),&oHatchLoopRec);
          assert(iStat == 0);

          // write record data to dxflib object
          oHatchLoopRec.WritToDL(&oDL_HatchLoop);

          // write next Hatch loop into dxf file
          this->dxf->writeHatchLoop1( *this->dw,
                                    oDL_HatchLoop);
        }
        break;
        case RS2::EntityHatchEdge:
        {
          sstDxf03FncHatchEdgeCls *oLocSstFncHatchEdge = NULL;
          oLocSstFncHatchEdge = this->poDxfDb->getSstFncHatchEdge();

          sstDxf03TypHatchEdgeCls oHatchEdgeRec;
          DL_HatchEdgeData oDL_HatchEdge;

          iStat = oLocSstFncHatchEdge->Read(0,oMainRec.getTypeID(),&oHatchEdgeRec);
          assert(iStat == 0);

          // write record data to dxflib object
          oHatchEdgeRec.WritToDL(&oDL_HatchEdge);

          // write next Hatch edge into dxf file
          this->dxf->writeHatchEdge( *this->dw,
                                    oDL_HatchEdge);
        }
        break;
        default:
          break;
        }

      }
      else break;

    }

    // if new entity-type, then write open polyline or hatch and close
    iStat = this->WriteOpenEntities(0);

    // end loop over all records in main table
    dxf->writeEndBlock(*dw, oBlkRec.getName());
  }


  // if new entity-type, then write open polyline or hatch and close
  // iStat = this->WriteOpenEntities(0);

  // dxf->writeEndBlock(*dw, oBlkRec.getName());

  this->dw->sectionEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstDxf03WriteCls::WrtSecTypes (int          iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Section Types -------------------------------------------------------------



  this->dw->sectionTables();
  this->dxf->writeVPort(*this->dw);
  this->dw->tableLinetypes(25);
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("BYBLOCK","Description",0,0,0.0)); //   ("BYBLOCK", 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("BYLAYER", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("CONTINUOUS", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("ACAD_ISO02W100", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("ACAD_ISO03W100", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("ACAD_ISO04W100", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("ACAD_ISO05W100", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("BORDER", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("BORDER2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("BORDERX2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("CENTER", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("CENTER2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("CENTERX2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DASHDOT", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DASHDOT2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DASHDOTX2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DASHED", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DASHED2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DASHEDX2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DIVIDE", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DIVIDE2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DIVIDEX2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DOT", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DOT2", "Description",0,0,0.0));  // 0));
  this->dxf->writeLinetype(*this->dw, DL_LinetypeData("DOTX2", "Description",0,0,0.0));  // 0));
  this->dw->tableEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstDxf03WriteCls::WrtSecStyles (int          iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;


  //--- Section Styles

  this->dxf->writeStyle(*this->dw,DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "standard", ""));
  this->dxf->writeView(*this->dw);
  this->dxf->writeUcs(*this->dw);

  this->dw->tableAppid(1);
  this->dw->tableAppidEntry(0x12);
  this->dw->dxfString(2, "ACAD");
  this->dw->dxfInt(70, 0);
  this->dw->tableEnd();
  this->dxf->writeDimStyle(*this->dw,
                    1,
                    1,
                    1,
                    1,
                    1);
  this->dxf->writeBlockRecord(*this->dw);
  this->dxf->writeBlockRecord(*this->dw, "myblock1");
  this->dxf->writeBlockRecord(*this->dw, "myblock2");
  this->dw->tableEnd();
  this->dw->sectionEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstDxf03WriteCls::WrtSecEntities (int          iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //-- Sections Entities

  this->dw->sectionEntities();

  sstDxf03FncMainCls *oLocSstFncMain = NULL;              /**< main Table object */
  sstDxf03TypMainCls oMainRec;
  oLocSstFncMain = this->poDxfDb->getSstFncMain();

  sstDxf03FncLayCls *oLocSstFncLay = NULL;              /**< layer Table object */
  sstDxf03TypLayCls oLayRec;
  oLocSstFncLay = this->poDxfDb->getSstFncLay();

  sstDxf03FncBlkCls *oLocSstFncBlk = NULL;              /**< Block Table object */
  sstDxf03TypBlkCls oBlkRec;
  oLocSstFncBlk = this->poDxfDb->getSstFncBlk();

  sstDxf03FncLTypeCls *oLocSstFncLType = NULL;              /**< LType Table object */
  sstDxf03TypLTypeCls oLTypeRec;
  oLocSstFncLType = this->poDxfDb->getSstFncLType();

//  sstDxf03FncInsertCls *oLocSstFncInsert = NULL;        /**< insert recmem object */
//  oLocSstFncInsert = this->oDxfDb.getSstFncInsert();
  // dREC04RECNUMTYP dNumInserts = oLocSstFncInsert->count();

  dREC04RECNUMTYP dNumMains = oLocSstFncMain->count();
  for (dREC04RECNUMTYP ii=1;ii <= dNumMains;ii++)
  {
    iStat = oLocSstFncMain->Read( 0, ii, &oMainRec);
    std::string oSectStr = oMainRec.getSectString();
    iStat = oSectStr.compare("L");
    if(iStat == 0)
    {  // we are inside Layer section

      oLocSstFncLay->Read(0,oMainRec.getLayBlockID(),&oLayRec);


    switch (oMainRec.getEntityType())
    {
    case RS2::EntityArc:
    {

      sstDxf03FncArcCls *oLocSstFncArc = NULL;              /**< Arc recmem object */
      sstDxf03TypArcCls oArcRec;
      oLocSstFncArc = this->poDxfDb->getSstFncArc();

      // if new entity-type, then write open polyline or hatch and close
      iStat = this->WriteOpenEntities(0);

      iStat = oLocSstFncArc->Read(0,oMainRec.getTypeID(),&oArcRec);
      DL_ArcData oDL_Arc( 0.0,0.0,0.0,
                          1.0,        // Radius
                          0.0,0.0);   // Angle1, angle2
      oArcRec.WritToDL(&oDL_Arc);

      DL_Attributes oAttributes;  // Dxflib Attributes
      oArcRec.BaseWritToDL(&oAttributes);
      oAttributes.setLayer(oLayRec.getName());
      // oAttributes.setLineType("BYBLOCK");
      // set Blockname
      // oDL_Insert.name = "myblock1";

      // write next insert into dxf file
      this->dxf->writeArc(  *this->dw, oDL_Arc, oAttributes);

      this->poDxfDb->setActEntType(oMainRec.getEntityType());
      this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());

      break;
    }
    case RS2::EntityCircle:
    {

      sstDxf03FncCircleCls *oLocSstFncCircle = NULL;              /**< Arc recmem object */
      sstDxf03TypCircleCls oCircleRec;
      oLocSstFncCircle = this->poDxfDb->getSstFncCircle();

      // if new entity-type, then write open polyline or hatch and close
      iStat = this->WriteOpenEntities(0);

      iStat = oLocSstFncCircle->Read(0,oMainRec.getTypeID(),&oCircleRec);
      DL_CircleData oDL_Circle(0.0,0.0,0.0,0.0);
      oCircleRec.WritToDL(&oDL_Circle);

      DL_Attributes oAttributes;  // Dxflib Attributes
      oCircleRec.BaseWritToDL(&oAttributes);
      oAttributes.setLayer(oLayRec.getName());
      // oAttributes.setLineType("BYBLOCK");
      // set Blockname
      // oDL_Insert.name = "myblock1";

      // write next insert into dxf file
      this->dxf->writeCircle(  *this->dw, oDL_Circle, oAttributes);

      this->poDxfDb->setActEntType(oMainRec.getEntityType());
      this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());

      break;
    }
    case RS2::EntityMText:
    {

      sstDxf03FncMTextCls *oLocSstFncMText = NULL;              /**< Arc recmem object */
      sstDxf03TypMTextCls oMTextRec;
      oLocSstFncMText = this->poDxfDb->getSstFncMText();

      // if new entity-type, then write open polyline or hatch and close
      iStat = this->WriteOpenEntities(0);

      iStat = oLocSstFncMText->Read(0,oMainRec.getTypeID(),&oMTextRec);
      DL_MTextData oDL_MText(0,0,0,0,0,0,0,0,0,0,0,0,"","",0);
      oMTextRec.WritToDL(&oDL_MText);

      DL_Attributes oAttributes;  // Dxflib Attributes
      oMTextRec.BaseWritToDL(&oAttributes);
      oAttributes.setLayer(oLayRec.getName());
      // oAttributes.setLineType("BYBLOCK");
      // set Blockname
      // oDL_Insert.name = "myblock1";

      // write next insert into dxf file
      this->dxf->writeMText(  *this->dw, oDL_MText, oAttributes);

      this->poDxfDb->setActEntType(oMainRec.getEntityType());
      this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());

      break;
    }
    case RS2::EntityText:
    {

      sstDxf03FncTextCls *oLocSstFncText = NULL;              /**< Arc recmem object */
      sstDxf03TypTextCls oTextRec;
      oLocSstFncText = this->poDxfDb->getSstFncText();

      // if new entity-type, then write open polyline or hatch and close
      iStat = this->WriteOpenEntities(0);

      iStat = oLocSstFncText->Read(0,oMainRec.getTypeID(),&oTextRec);
      DL_TextData oDL_Text(0,0,0,0,0,0,0,0,0,0,0,"","",0);
      oTextRec.WritToDL(&oDL_Text);

      DL_Attributes oAttributes;  // Dxflib Attributes
      oTextRec.BaseWritToDL(&oAttributes);
      oAttributes.setLayer(oLayRec.getName());
      // oAttributes.setLineType("BYBLOCK");
      // set Blockname
      // oDL_Insert.name = "myblock1";

      // write next insert into dxf file
      this->dxf->writeText(  *this->dw, oDL_Text, oAttributes);

      this->poDxfDb->setActEntType(oMainRec.getEntityType());
      this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());

      break;
    }
    case RS2::EntityInsert:
    {
      sstDxf03FncInsertCls *oLocSstFncInsert = NULL;        /**< insert recmem object */
      oLocSstFncInsert = this->poDxfDb->getSstFncInsert();

      // if new entity-type, then write open polyline or hatch and close
      iStat = this->WriteOpenEntities(0);

      sstDxf03TypInsertCls oInsertRec;
      DL_InsertData oDL_Insert("",
                               0.0,0.0,0.0,
                               1.0,1.0,0.0,
                               0.0,
                               1,1,
                               1.0,1.0);

      iStat = oLocSstFncInsert->Read(0,oMainRec.getTypeID(),&oInsertRec);
      assert(iStat == 0);
      // iStat = oLocSstFncLay->Read(0,oInsertRec.getLayerID(),&oLayRec);
      // assert(iStat == 0);
      iStat = oLocSstFncBlk->Read(0,oInsertRec.getBlockID(),&oBlkRec);
      assert(iStat == 0);

      // write Insert record data to dxflib insert
      oInsertRec.WritToDL(&oDL_Insert);

      // set Blockname
      // oDL_Insert.name = "myblock1";
      oDL_Insert.name = oBlkRec.getName();

      // write next insert into dxf file
      double dLineTypeScale = 1.0;
      this->dxf->writeInsert(  *this->dw,
                                oDL_Insert,
                                DL_Attributes(oLayRec.getName(), 256, -1, "BYLAYER", dLineTypeScale));

      this->poDxfDb->setActEntType(oMainRec.getEntityType());
      this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());

      break;
    }

    case RS2::EntityPolyline:
    {
      sstDxf03TypPolylineCls oPolylineRec;
      sstDxf03FncPolylineCls *oLocSstFncPolyline = NULL;
      oLocSstFncPolyline = this->poDxfDb->getSstFncPolyline();

      // if new entity-type, then write open polyline or hatch and close
      iStat = this->WriteOpenEntities(0);

      iStat = oLocSstFncPolyline->Read(0,oMainRec.getTypeID(),&oPolylineRec);
      assert(iStat == 0);

      // write record data to dxflib object
      DL_PolylineData oDL_Polyline(0,0,0,0);
      oPolylineRec.WritToDL(&oDL_Polyline);

      iStat = oLocSstFncLType->Read ( 0, oPolylineRec.getLinetypeID(), &oLTypeRec);
      assert(iStat == 0);

      DL_Attributes oAttributes;  // Dxflib Attributes
      oPolylineRec.BaseWritToDL(&oAttributes);
//      oAttributes.setColor(oPolylineRec.getColor());
//      oAttributes.setColor24(oPolylineRec.getColor24());
//      oAttributes.setHandle(oPolylineRec.getHandle());
      oAttributes.setLayer(oLayRec.getName());
      oAttributes.setLinetype(oLTypeRec.getName());
//      oAttributes.setWidth(oPolylineRec.getWidth());

      if ( strncmp( oLTypeRec.getName(), "BYLAYER", dSSTDXF03LTYPENAMELEN) == 0)
      {  // LineType / width by layer

        // Read linetype from layer
        iStat = oLocSstFncLType->Read ( 0, oLayRec.getLinetypeID(), &oLTypeRec);
        assert(iStat == 0);

        oAttributes.setLinetype(oLTypeRec.getName());

      }

      if ( oPolylineRec.getColor() == 256)
      {  // Color by Layer
        oAttributes.setColor(oLayRec.getColor());
      }
      if ( oPolylineRec.getWidth() == -1)
      {  // Color by Layer
        oAttributes.setWidth(oLayRec.getWidth());
      }

      // write next insert into dxf file
      this->dxf->writePolyline(  *this->dw, oDL_Polyline, oAttributes);

      this->poDxfDb->setActEntType(oMainRec.getEntityType());
      this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());

      break;
    }
    case RS2::EntityVertex:
    {
      sstDxf03FncVertexCls *oLocSstFncVertex = NULL;
      oLocSstFncVertex = this->poDxfDb->getSstFncVertex();

      sstDxf03TypVertexCls oVertexRec;
      DL_VertexData oDL_Vertex(0.0,0.0,0.0,0.0);

      iStat = oLocSstFncVertex->Read(0,oMainRec.getTypeID(),&oVertexRec);
      assert(iStat == 0);

      // write record data to dxflib object
      oVertexRec.WritToDL(&oDL_Vertex);

      // write next insert into dxf file
      this->dxf->writeVertex(  *this->dw,
                                oDL_Vertex);

      break;
    }
    case RS2::EntityPoint:
    {
      sstDxf03FncPointCls *oLocSstFncPoint = NULL;
      oLocSstFncPoint = this->poDxfDb->getSstFncPoint();

      // if new entity-type, then write open polyline or hatch and close
      iStat = this->WriteOpenEntities(0);

      sstDxf03TypPointCls oPointRec;
      DL_PointData oDL_Point;

      iStat = oLocSstFncPoint->Read(0,oMainRec.getTypeID(),&oPointRec);
      assert(iStat == 0);

      // write record data to dxflib object
      oPointRec.WritToDL(&oDL_Point);

      DL_Attributes oAttributes;  // Dxflib Attributes
      oPointRec.BaseWritToDL(&oAttributes);
      oAttributes.setLayer(oLayRec.getName());
      // oAttributes.setLineType("BYBLOCK");

      // write next insert into dxf file
      this->dxf->writePoint(  *this->dw,
                                oDL_Point, oAttributes);

      this->poDxfDb->setActEntType(oMainRec.getEntityType());
      this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());

      break;
    }
    case RS2::EntityLine:
    {
      sstDxf03FncLineCls *oLocSstFncLine = NULL;
      oLocSstFncLine = this->poDxfDb->getSstFncLine();

      // if new entity-type, then write open polyline or hatch and close
      iStat = this->WriteOpenEntities(0);

      sstDxf03TypLineCls oLineRec;
      DL_LineData oDL_Line(0,0,0,0,0,0);

      iStat = oLocSstFncLine->Read(0,oMainRec.getTypeID(),&oLineRec);
      assert(iStat == 0);

      // write record data to dxflib object
      oLineRec.WritToDL(&oDL_Line);

      DL_Attributes oAttributes;  // Dxflib Attributes
      oLineRec.BaseWritToDL(&oAttributes);
      oAttributes.setLayer(oLayRec.getName());
      // oAttributes.setLineType("BYBLOCK");

      // write next insert into dxf file
      this->dxf->writeLine(  *this->dw,
                                oDL_Line, oAttributes);

      this->poDxfDb->setActEntType(oMainRec.getEntityType());
      this->poDxfDb->setMainTabSectEntStart(oMainRec.getTypeID());

      break;
    }
    case RS2::EntityHatch:
    {
      sstDxf03FncHatchCls *oLocSstFncHatch = NULL;
      oLocSstFncHatch = this->poDxfDb->getSstFncHatch();

      sstDxf03TypHatchCls oHatchRec;
      DL_HatchData oDL_Hatch;

      iStat = oLocSstFncHatch->Read(0,oMainRec.getTypeID(),&oHatchRec);
      assert(iStat == 0);

      iStat = oLocSstFncLType->Read ( 0, oHatchRec.getLinetypeID(), &oLTypeRec);
      assert(iStat == 0);

      DL_Attributes oDL_Attributes;
      oDL_Attributes.setLayer(oLayRec.getName());
      oDL_Attributes.setColor( oHatchRec.getColor());
      oDL_Attributes.setWidth( oHatchRec.getWidth());
      oDL_Attributes.setHandle( oHatchRec.getHandle());
      oDL_Attributes.setLinetype( oLTypeRec.getName());


      // write record data to dxflib object
      oHatchRec.WritToDL(&oDL_Hatch);
      oDL_Hatch.pattern = "SOLID";

      // write next Hatch into dxf file
      this->dxf->writeHatch1( *this->dw,
                                oDL_Hatch, oDL_Attributes);
      break;
    }
    case RS2::EntityHatchLoop:
    {
      sstDxf03FncHatchLoopCls *oLocSstFncHatchLoop = NULL;
      oLocSstFncHatchLoop = this->poDxfDb->getSstFncHatchLoop();

      sstDxf03TypHatchLoopCls oHatchLoopRec;
      DL_HatchLoopData oDL_HatchLoop;

      iStat = oLocSstFncHatchLoop->Read(0,oMainRec.getTypeID(),&oHatchLoopRec);
      assert(iStat == 0);

      // write record data to dxflib object
      oHatchLoopRec.WritToDL(&oDL_HatchLoop);

      // write next Hatch loop into dxf file
      this->dxf->writeHatchLoop1( *this->dw,
                                oDL_HatchLoop);
      break;
    }
    case RS2::EntityHatchEdge:
    {
      sstDxf03FncHatchEdgeCls *oLocSstFncHatchEdge = NULL;
      oLocSstFncHatchEdge = this->poDxfDb->getSstFncHatchEdge();

      sstDxf03TypHatchEdgeCls oHatchEdgeRec;
      DL_HatchEdgeData oDL_HatchEdge;

      iStat = oLocSstFncHatchEdge->Read(0,oMainRec.getTypeID(),&oHatchEdgeRec);
      assert(iStat == 0);

      // write record data to dxflib object
      oHatchEdgeRec.WritToDL(&oDL_HatchEdge);

      // write next Hatch edge into dxf file
      this->dxf->writeHatchEdge( *this->dw,
                                oDL_HatchEdge);
      break;
    }
      default:
        break;
      }

    }  // End inside layer
    }  // end switch

  // if new entity-type, then write open polyline or hatch and close
  iStat = this->WriteOpenEntities(0);

  this->dw->sectionEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstDxf03WriteCls::WrtSecObjects (int          iKey)
//-----------------------------------------------------------------------------
{
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  this->dxf->writeObjects(*this->dw);
  this->dxf->writeObjectsEnd(*this->dw);

  return 0;
}
//=============================================================================
int sstDxf03WriteCls::WrtDss2PolyLine (int           iKey,
                            sstRec04Cls  *sPntDss)
//-----------------------------------------------------------------------------
{
  RS_Vector     sD3Pnt;
  dREC04RECNUMTYP   lAnzDs=0;
  dREC04RECNUMTYP   ii=0;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Die Anzahl der aktuell gespeicherten Datensдtze zurьckgeben.
  // iStat = DS1_DsAnz ( 0, sPntDss, &lAnzDs);
  lAnzDs = sPntDss->count();

  double dLineTypeScale = 1.0;
  this->dxf->writePolyline(*this->dw, DL_PolylineData (lAnzDs,0,0,0),
                         DL_Attributes("mainlayer", 256, -1, "BYLAYER", dLineTypeScale));

  for (ii=1; ii<=lAnzDs; ii++)
  {
    // tat = sPntDss->Read(0,ii,&sD3Pnt);

    this->dxf->writeVertex( *this->dw, DL_VertexData(sD3Pnt.x, sD3Pnt.y, 0.0));
  }

  this->dxf->writePolylineEnd(*this->dw);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
void sstDxf03WriteCls::SetDxfFilNam(std::string oTmpDxfFilNam)
{
  // std::string oTmpStr;
  sstMisc01FilNamCls oFilNam;
  // oTmpStr = cTmpDxfFilNam;
  // Remove extension from dxf file name and store in sst dxf read object
  oFilNam.RemoveExtension(0,"dxf", oTmpDxfFilNam,&this->oDxfFilNam);
}
//=============================================================================
int sstDxf03WriteCls::ReadAllCsvFiles(int iKey)
{
  if ( iKey != 0) return -1;

  return this->poDxfDb->ReadAllCsvFiles(0,this->oDxfFilNam);
}
//=============================================================================
int sstDxf03WriteCls::WriteOpenEntities(int iKey)
{
  if ( iKey != 0) return -1;

  RS2::EntityType eType = this->poDxfDb->getActEntType();

  if(eType == RS2::EntityPolyline)
  {
    this->dxf->writePolylineEnd(*this->dw);
    this->poDxfDb->setActEntType(RS2::EntityUnknown);
  }

  return 0;
}
//=============================================================================

