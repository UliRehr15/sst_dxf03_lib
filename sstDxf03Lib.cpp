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
// sstDxf03Lib.cpp    18.11.16  Re.    18.11.16  Re.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>
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
sstDxf03DbCls::sstDxf03DbCls(sstMisc01PrtFilCls *oTmpPrt)
{
  // Constructor
  this->poDxf03DbIntern = new sstDxf03DatabaseCls(oTmpPrt);
}
//=============================================================================
sstDxf03DbCls::~sstDxf03DbCls()
{
  // Destructor
  delete(this->poDxf03DbIntern);
}
//=============================================================================
int sstDxf03DbCls::WriteNewCircle(int iKey,
                   const DL_CircleData oDLCircle,
                   const DL_Attributes attributes,
                   dREC04RECNUMTYP *oEntRecNo,
                   dREC04RECNUMTYP *oMainRecNo)
{
  return this->poDxf03DbIntern->WriteNewCircle(iKey,oDLCircle,attributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::OpenNewHatch(int                  iKey,
                                const DL_HatchData   oDLHatch,
                                const DL_Attributes  oDLAttributes,
                                dREC04RECNUMTYP     *oEntRecNo,
                                dREC04RECNUMTYP     *oMainRecNo)
//-----------------------------------------------------------------------------
{
  // int iRet  = 0;
  // int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  return this->poDxf03DbIntern->OpenNewHatch(iKey,oDLHatch,oDLAttributes,oEntRecNo, oMainRecNo);
}
//==============================================================================
int sstDxf03DbCls::WriteNewHatchEdge (int                    iKey,
                                      const DL_HatchEdgeData oDLHatchEdge,
                                      dREC04RECNUMTYP       *oEntRecNo,
                                      dREC04RECNUMTYP       *oMainRecNo)
//-----------------------------------------------------------------------------
{
  // int iRet  = 0;
  // int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  return this->poDxf03DbIntern->WriteNewHatchEdge(iKey,oDLHatchEdge,oEntRecNo, oMainRecNo);
}
//=============================================================================
int sstDxf03DbCls::WritAll2DxfFil(int iKey, const std::string oDxfFilNam)
{
  return this->poDxf03DbIntern->WritAll2DxfFil(iKey, oDxfFilNam);
}
//=============================================================================
int sstDxf03DbCls::WritAll2Csv(int iKey, const std::string oDxfFilNam)
{
  return this->poDxf03DbIntern->WritAll2Csv(iKey,oDxfFilNam);
}
//=============================================================================
int sstDxf03DbCls::ReadAllCsvFiles(int iKey, std::string oDxfFilNam)
{
  return this->poDxf03DbIntern->ReadAllCsvFiles(iKey, oDxfFilNam);
}
//=============================================================================
int sstDxf03DbCls::ReadAllFromDxf(int iKey, const std::string oDxfFilNam)
{
  return this->poDxf03DbIntern->ReadAllFromDxf(iKey, oDxfFilNam);
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DbCls::MainCount()
{
  return this->poDxf03DbIntern->MainCount();
}
//=============================================================================
dREC04RECNUMTYP sstDxf03DbCls::EntityCount(RS2::EntityType eEntityType)
{
  return this->poDxf03DbIntern->EntityCount(eEntityType);
}
//=============================================================================
int sstDxf03DbCls::ReadHatch ( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchData *oDLHatch, DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadHatch(iKey,dRecNo, oDLHatch, oDLAttributes);
}
//=============================================================================
int sstDxf03DbCls::ReadHatchEdge( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchEdgeData *oDLHatchEdge)
{
  return this->poDxf03DbIntern->ReadHatchEdge(iKey, dRecNo, oDLHatchEdge);
}
//=============================================================================
int sstDxf03DbCls::ReadHatchLoop( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchLoopData *oDLHatchLoop)
{
  return this->poDxf03DbIntern->ReadHatchLoop(iKey, dRecNo, oDLHatchLoop);
}
//=============================================================================
int sstDxf03DbCls::ReadCircle ( int iKey, dREC04RECNUMTYP dRecNo, DL_CircleData *oDLCircle, DL_Attributes *oDLAttributes)
{
  return this->poDxf03DbIntern->ReadCircle(iKey,dRecNo, oDLCircle, oDLAttributes);
}
//=============================================================================
int sstDxf03DbCls::ReadMainTable( int iKey, dREC04RECNUMTYP dMainRecNo, RS2::EntityType *eEntityType, dREC04RECNUMTYP *dEntRecNo)
{
  return this->poDxf03DbIntern->ReadMainTable(iKey,dMainRecNo, eEntityType, dEntRecNo);
}
//=============================================================================
