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
// sstDxf03Main.cpp    01.11.16  Re.    12.04.16  Re.
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
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf03Lib.h>

#include "sstDxf03LibInt.h"

//=============================================================================
sstDxf03TypMainCls::sstDxf03TypMainCls()
{
  memset(this->cSectionType,0,2);
  this->dMainID = 0;
  this->dLayBlockID = 0;
  this->dTypeID = 0;
  this->eEntityType = RS2::EntityUnknown;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypMainCls::getMainID() const
{
  return dMainID;
}
//=============================================================================
void sstDxf03TypMainCls::setMainID(const dREC04RECNUMTYP &value)
{
  dMainID = value;
}
//=============================================================================
std::string sstDxf03TypMainCls::getSectString() const
{
  std::string oTmpString;
  oTmpString = this->cSectionType;
  return oTmpString;
}
//=============================================================================
void sstDxf03TypMainCls::setSectString(const std::string &oSectString)
{
  strncpy(this->cSectionType,oSectString.c_str(),2);
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypMainCls::getLayBlockID() const
{
  return dLayBlockID;
}
//=============================================================================
void sstDxf03TypMainCls::setLayBlockID(const dREC04RECNUMTYP &value)
{
  dLayBlockID = value;
}
//=============================================================================
RS2::EntityType sstDxf03TypMainCls::getEntityType() const
{
  return eEntityType;
}
//=============================================================================
void sstDxf03TypMainCls::setEntityType(const RS2::EntityType &value)
{
  eEntityType = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypMainCls::getTypeID() const
{
  return dTypeID;
}
//=============================================================================
void sstDxf03TypMainCls::setTypeID(const dREC04RECNUMTYP &value)
{
  dTypeID = value;
}
//=============================================================================
sstDxf03FncMainCls::sstDxf03FncMainCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypMainCls))
{

}
//=============================================================================
// Csv Read Function
int sstDxf03FncMainCls::Csv_Read(int iKey,
                                 std::string *sErrTxt,
                                 std::string *ssstDxfLib_Str,
                                 sstDxf03TypMainCls *osstDxf03TypMainCls)
{
  dREC04RECNUMTYP dTmpNumber = 0;
  dREC04RECNUMTYP dTmpNumSect = 0;
  dREC04RECNUMTYP dTmpNumType = 0;
  std::string oTmpSectString;
  std::string oTmpTypeString;
  RS2::EntityType eEntityType = RS2::EntityUnknown;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //  number; Section; numSect;  Type; numType;
  //       1;       B;    567;    Arc;     234;

  oCsvRow.SetReadPositon(0,0);

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dTmpNumber);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Str( 0, ssstDxfLib_Str, &oTmpSectString);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dTmpNumSect);
  if (iStat >= 0)
  {
    iStat = oCsvRow.CsvString2_Str( 0, ssstDxfLib_Str, &oTmpTypeString);
    sstDxf03EntityTypeCls oEntityType;
    eEntityType = oEntityType.String2Enum(oTmpTypeString);
    if (eEntityType == RS2::EntityUnknown)
       assert(0);
  }
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dTmpNumType);

  if (iStat >= 0)
  {  // no read error until now
    // write data from csv file row into main record object
    osstDxf03TypMainCls->setMainID(dTmpNumber);
    osstDxf03TypMainCls->setSectString(oTmpSectString);
    osstDxf03TypMainCls->setLayBlockID(dTmpNumSect);
    osstDxf03TypMainCls->setEntityType(eEntityType);
    osstDxf03TypMainCls->setTypeID(dTmpNumType);
  }
  else
  {
    *sErrTxt = oCsvRow.GetErrorString();
  }

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

//  Bloc Function1 End
  return iStat;
}
//=============================================================================
// Csv Write Function
int sstDxf03FncMainCls::Csv_Write(int iKey,
                                  sstDxf03TypMainCls *poSstMain,
                                  std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  //  number; Section; numSect;  Type; numType;
  //       1;       B;    567;    Arc;     234;


  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstMain->getMainID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Str_2String( 0, poSstMain->getSectString(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstMain->getLayBlockID(), ssstDxfLib_Str);
  if (iStat >= 0)
  {
    sstDxf03EntityTypeCls oEntityType;
    std::string oEntityStr;
    oEntityStr = oEntityType.Enum2String(poSstMain->getEntityType());
    iStat = oCsvRow.Csv_Str_2String( 0, oEntityStr, ssstDxfLib_Str);
  }
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstMain->getTypeID(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstInsert->getLayerID(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstInsert->getBlockID(), ssstDxfLib_Str);

//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String( 0, poSstInsert->getIpx(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getIpy(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getIpz(), ssstDxfLib_Str);

//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstInsert->getColor(), ssstDxfLib_Str);


//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String( 0, poSstInsert->getCx(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getCy(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getCz(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getRadius(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getAngle1(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getAngle2(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstInsert->getColor(), ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf03FncMainCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  //  number; Section; numSect;  Type; numType;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  oTitelStr = "Number";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Section";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "NumSect";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Type";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "NumType";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  return iStat;
}
//=============================================================================
int sstDxf03FncMainCls::ReadCsvFile(int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oCsvFilLayer;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oCsvFilLayer.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;

  std::string oLayStr;
  std::string oErrStr;
  dREC04RECNUMTYP dRecNo = 0;
  int iStat1 = 0;
  // Read title row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  if (iStat1 < 0) return -3;

  // Read first data row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  while (iStat1 >= 0)
  {
    sstDxf03TypMainCls oSstMain;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstMain);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstMain,&dRecNo);

    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncMainCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Main data to Csv file
  oCsvFilNam = oDxfFilNam + "_Main.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypMainCls oDxfMain;
    iStat = this->Read(0,kk,&oDxfMain);

    oDxfMain.setMainID(kk);

    this->Csv_Write( 0, &oDxfMain, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
