
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
//  sstDxf03HatchEdge.cpp   01.11.16  Re.   29.04.16  Re.
//
//  Functions for sst Dxf Hatch Edge Classes
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
// Constructor
sstDxf03TypHatchEdgeCls::sstDxf03TypHatchEdgeCls()
{
  this->dRecordID = 0;
  this->dParentID = 0;
  this->angle1 = 0;
  this->angle2 = 0;
  this->ccw = 0;
  // this->angle1 = oDLHatchEdge.controlPoints;
  this->cx = 0;
  this->cy = 0;
  this->defined = 0;
  this->degree = 0;
  this->endTangentX = 0;
  this->endTangentY = 0;
  // this->angle1 = oDLHatchEdge.fitPoints;
  // this->angle1 = oDLHatchEdge.knots;
  this->mx = 0;
  this->my = 0;
  this->nControl = 0;
  this->nFit = 0;
  this->nKnots = 0;
  this->periodic = 0;
  this->radius = 0;
  this->ratio = 0;
  this->rational = 0;
  this->startTangentX = 0;
  this->startTangentY = 0;
  this->type = 0;
  // this->angle1 = oDLHatchEdge.vertices;
  // this->angle1 = oDLHatchEdge.weights;
  this->x1 = 0;
  this->y1 = 0;
  this->x2 = 0;
  this->y2 = 0;
}
//=============================================================================
// Set Test Data
int sstDxf03TypHatchEdgeCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;

  return 0;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::ReadFromDL(const DL_HatchEdgeData oDLHatchEdge)
{
  this->angle1 = oDLHatchEdge.angle1;
  this->angle2 = oDLHatchEdge.angle2;
  this->ccw = oDLHatchEdge.ccw;
  // this->angle1 = oDLHatchEdge.controlPoints;
  this->cx = oDLHatchEdge.cx;
  this->cy = oDLHatchEdge.cy;
  this->defined = oDLHatchEdge.defined;
  // this->degree = oDLHatchEdge.degree;
  this->setDegree(oDLHatchEdge.degree);
  this->endTangentX = oDLHatchEdge.endTangentX;
  this->endTangentY = oDLHatchEdge.endTangentY;
  // this->angle1 = oDLHatchEdge.fitPoints;
  // this->angle1 = oDLHatchEdge.knots;
  this->mx = oDLHatchEdge.mx;
  this->my = oDLHatchEdge.my;
//  this->nControl = oDLHatchEdge.nControl;
//  this->nFit = oDLHatchEdge.nFit;
//  this->nKnots = oDLHatchEdge.nKnots;
  this->setNControl(oDLHatchEdge.nControl);
  this->setNFit(oDLHatchEdge.nFit);
  this->setNKnots( oDLHatchEdge.nKnots);
  this->periodic = oDLHatchEdge.periodic;
  this->radius = oDLHatchEdge.radius;
//  bool bResult = isnan(oDLHatchEdge.ratio);
//  this->ratio = dSSTSTR01_UNDEF_DOUBLE;
//  if (oDLHatchEdge.ratio <= dSSTSTR01_UNDEF_DOUBLE) this->ratio = dSSTSTR01_UNDEF_DOUBLE;
//  else if (oDLHatchEdge.ratio >= -dSSTSTR01_UNDEF_DOUBLE) this->ratio = dSSTSTR01_UNDEF_DOUBLE;
  //  else this->ratio = oDLHatchEdge.ratio;
  this->ratio = oDLHatchEdge.ratio;
  this->rational = oDLHatchEdge.rational;
  this->startTangentX = oDLHatchEdge.startTangentX;
  this->startTangentY = oDLHatchEdge.startTangentY;
  this->type = oDLHatchEdge.type;
  // this->angle1 = oDLHatchEdge.vertices;
  // this->angle1 = oDLHatchEdge.weights;
  this->x1 = oDLHatchEdge.x1;
  this->y1 = oDLHatchEdge.y1;
  this->x2 = oDLHatchEdge.x2;
  this->y2 = oDLHatchEdge.y2;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::WritToDL(DL_HatchEdgeData *poDLHatchEdge)
{
  poDLHatchEdge->angle1 = this->angle1;
  poDLHatchEdge->angle2 = this->angle2;
  poDLHatchEdge->ccw = this->ccw;
  // this->angle1 = oDLHatchEdge.controlPoints;
  poDLHatchEdge->cx = this->cx;
  poDLHatchEdge->cy = this->cy;
  poDLHatchEdge->defined = this->defined;
  poDLHatchEdge->degree = this->degree;
  poDLHatchEdge->endTangentX = this->endTangentX;
  poDLHatchEdge->endTangentY = this->endTangentY;
  // this->angle1 = oDLHatchEdge.fitPoints;
  // this->angle1 = oDLHatchEdge.knots;
  poDLHatchEdge->mx = this->mx;
  poDLHatchEdge->my = this->my;
  poDLHatchEdge->nControl = this->nControl;
  poDLHatchEdge->nFit = this->nFit;
  poDLHatchEdge->nKnots = this->nKnots;
  poDLHatchEdge->periodic = this->periodic;
  poDLHatchEdge->radius = this->radius;
  poDLHatchEdge->ratio = this->ratio;
  poDLHatchEdge->rational = this->rational;
  poDLHatchEdge->startTangentX = this->startTangentX;
  poDLHatchEdge->startTangentY = this->startTangentY;
  poDLHatchEdge->type = this->type;
  // this->angle1 = oDLHatchEdge.vertices;
  // this->angle1 = oDLHatchEdge.weights;
  poDLHatchEdge->x1 = this->x1;
  poDLHatchEdge->y1 = this->y1;
  poDLHatchEdge->x2 = this->x2;
  poDLHatchEdge->y2 = this->y2;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypHatchEdgeCls::getRecordID() const
{
return dRecordID;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setRecordID(const dREC04RECNUMTYP &value)
{
dRecordID = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf03TypHatchEdgeCls::getParentID() const
{
return dParentID;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setParentID(const dREC04RECNUMTYP &value)
{
dParentID = value;
}
//=============================================================================
bool sstDxf03TypHatchEdgeCls::getDefined() const
{
return defined;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setDefined(bool value)
{
defined = value;
}
//=============================================================================
int sstDxf03TypHatchEdgeCls::getType() const
{
return type;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setType(int value)
{
type = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getX1() const
{
return x1;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setX1(double value)
{
x1 = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getY1() const
{
return y1;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setY1(double value)
{
y1 = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getX2() const
{
return x2;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setX2(double value)
{
x2 = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getY2() const
{
return y2;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setY2(double value)
{
y2 = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getCx() const
{
return cx;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setCx(double value)
{
cx = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getCy() const
{
return cy;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setCy(double value)
{
cy = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getRadius() const
{
return radius;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setRadius(double value)
{
radius = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getAngle1() const
{
return angle1;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setAngle1(double value)
{
angle1 = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getAngle2() const
{
return angle2;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setAngle2(double value)
{
angle2 = value;
}
//=============================================================================
bool sstDxf03TypHatchEdgeCls::getCcw() const
{
return ccw;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setCcw(bool value)
{
ccw = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getMx() const
{
return mx;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setMx(double value)
{
mx = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getMy() const
{
return my;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setMy(double value)
{
my = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getRatio() const
{
return ratio;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setRatio(double value)
{
ratio = value;
}
//=============================================================================
unsigned int sstDxf03TypHatchEdgeCls::getDegree() const
{
return degree;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setDegree(unsigned int value)
{
  degree = dSSTSTR01_CUINT2_MAX;
  if (value >= dSSTSTR01_CUINT2_MAX) return;
//   if (value < 0) return;
  degree = value;
}
//=============================================================================
bool sstDxf03TypHatchEdgeCls::getRational() const
{
return rational;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setRational(bool value)
{
rational = value;
}
//=============================================================================
bool sstDxf03TypHatchEdgeCls::getPeriodic() const
{
return periodic;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setPeriodic(bool value)
{
periodic = value;
}
//=============================================================================
unsigned int sstDxf03TypHatchEdgeCls::getNKnots() const
{
return nKnots;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setNKnots(unsigned int value)
{
  nKnots = dSSTSTR01_CUINT2_MAX;
  if (value >= dSSTSTR01_CUINT2_MAX) return;
//   if (value < 0) return;
  nKnots = value;
}
//=============================================================================
unsigned int sstDxf03TypHatchEdgeCls::getNControl() const
{
return nControl;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setNControl(unsigned int value)
{
  nControl = dSSTSTR01_CUINT2_MAX;
  if (value >= dSSTSTR01_CUINT2_MAX) return;
//   if (value < 0) return;
  nControl = value;
}
//=============================================================================
unsigned int sstDxf03TypHatchEdgeCls::getNFit() const
{
return nFit;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setNFit(unsigned int value)
{
  nFit = dSSTSTR01_CUINT2_MAX;
  if (value >= dSSTSTR01_CUINT2_MAX) return;
//   if (value < 0) return;
  nFit = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getStartTangentX() const
{
return startTangentX;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setStartTangentX(double value)
{
startTangentX = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getStartTangentY() const
{
return startTangentY;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setStartTangentY(double value)
{
startTangentY = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getEndTangentX() const
{
return endTangentX;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setEndTangentX(double value)
{
endTangentX = value;
}
//=============================================================================
double sstDxf03TypHatchEdgeCls::getEndTangentY() const
{
return endTangentY;
}
//=============================================================================
void sstDxf03TypHatchEdgeCls::setEndTangentY(double value)
{
endTangentY = value;
}
//=============================================================================
// Constructor
sstDxf03FncHatchEdgeCls::sstDxf03FncHatchEdgeCls():sstDxf03FncBaseCls(sizeof(sstDxf03TypHatchEdgeCls))
{
  // this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf03TypHatchEdgeCls));
}
//=============================================================================
// Csv Read Function
int sstDxf03FncHatchEdgeCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf03TypHatchEdgeCls *osstDxf02TypHatchEdge)
{
  dREC04RECNUMTYP dLocRecordID = 0;
  dREC04RECNUMTYP dLocParentID = 0;
  bool bLocDefined;
  int iLocType;
  double dLocX1;
  double dLocY1;
  double dLocX2;
  double dLocY2;
  double dLocCx;
  double dLocCy;
  double dLocRadius;
  double dLocAngle1;
  double dLocAngle2;
  bool bLocCcw;
  double dLocMx;
  double dLocMy;
  double dLocRatio;
  unsigned int uiLocDegree;
  bool bLocRational;
  bool bLocPeriodic;
  unsigned int uiLocnKnots;
  unsigned int uiLocnControl;
  unsigned int uiLocnFit;
  // std::vector<std::vector<double> > controlPoints;
  // std::vector<double> knots;
  // std::vector<double> weights;
  // std::vector<std::vector<double> > fitPoints;
  double dLocStartTangentX;
  double dLocStartTangentY;
  double dLocEndTangentX;
  double dLocEndTangentY;
  // std::vector<std::vector<double> > vertices;

  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  //  bool defined;
  //  int type;
  //  double x1;
  //  double y1;
  //  double x2;
  //  double y2;
  //  double cx;
  //  double cy;
  //  double radius;
  //  double angle1;
  //  double angle2;
  //  bool ccw;
  //  double mx;
  //  double my;
  //  double ratio;
  //  unsigned int degree;
  //  bool rational;
  //  bool periodic;
  //  unsigned int nKnots;
  //  unsigned int nControl;
  //  unsigned int nFit;
  //  std::vector<std::vector<double> > controlPoints;
  //  std::vector<double> knots;
  //  std::vector<double> weights;
  //  std::vector<std::vector<double> > fitPoints;
  //  double startTangentX;
  //  double startTangentY;
  //  double endTangentX;
  //  double endTangentY;
  //  std::vector<std::vector<double> > vertices;

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocRecordID);
  if (iStat >= 0) osstDxf02TypHatchEdge->setRecordID(dLocRecordID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocParentID);
  if (iStat >= 0) osstDxf02TypHatchEdge->setParentID(dLocParentID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Bool( 0, ssstDxfLib_Str, &bLocDefined);
  if (iStat >= 0) osstDxf02TypHatchEdge->setDefined(bLocDefined);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocType);
  if (iStat >= 0) osstDxf02TypHatchEdge->setType(iLocType);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocX1);
  if (iStat >= 0) osstDxf02TypHatchEdge->setX1(dLocX1);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocY1);
  if (iStat >= 0) osstDxf02TypHatchEdge->setY1(dLocY1);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocX2);
  if (iStat >= 0) osstDxf02TypHatchEdge->setX2(dLocX2);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocY2);
  if (iStat >= 0) osstDxf02TypHatchEdge->setY2(dLocY2);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocCx);
  if (iStat >= 0) osstDxf02TypHatchEdge->setCx(dLocCx);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocCy);
  if (iStat >= 0) osstDxf02TypHatchEdge->setCy(dLocCy);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocRadius);
  if (iStat >= 0) osstDxf02TypHatchEdge->setRadius(dLocRadius);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocAngle1);
  if (iStat >= 0) osstDxf02TypHatchEdge->setAngle1(dLocAngle1);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocAngle2);
  if (iStat >= 0) osstDxf02TypHatchEdge->setAngle2(dLocAngle2);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Bool( 0, ssstDxfLib_Str, &bLocCcw);
  if (iStat >= 0) osstDxf02TypHatchEdge->setCcw(bLocCcw);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocMx);
  if (iStat >= 0) osstDxf02TypHatchEdge->setMx(dLocMx);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocMy);
  if (iStat >= 0) osstDxf02TypHatchEdge->setMy(dLocMy);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocRatio);
  if (iStat >= 0) osstDxf02TypHatchEdge->setRatio(dLocRatio);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt2( 0, ssstDxfLib_Str, &uiLocDegree);
  if (iStat >= 0) osstDxf02TypHatchEdge->setDegree(uiLocDegree);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Bool( 0, ssstDxfLib_Str, &bLocRational);
  if (iStat >= 0) osstDxf02TypHatchEdge->setRational(bLocRational);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Bool( 0, ssstDxfLib_Str, &bLocPeriodic);
  if (iStat >= 0) osstDxf02TypHatchEdge->setPeriodic(bLocPeriodic);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt2( 0, ssstDxfLib_Str, &uiLocnKnots);
  if (iStat >= 0) osstDxf02TypHatchEdge->setNKnots(uiLocnKnots);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt2( 0, ssstDxfLib_Str, &uiLocnControl);
  if (iStat >= 0) osstDxf02TypHatchEdge->setNControl(uiLocnControl);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt2( 0, ssstDxfLib_Str, &uiLocnFit);
  if (iStat >= 0) osstDxf02TypHatchEdge->setNFit(uiLocnFit);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocStartTangentX);
  if (iStat >= 0) osstDxf02TypHatchEdge->setStartTangentX(dLocStartTangentX);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocStartTangentY);
  if (iStat >= 0) osstDxf02TypHatchEdge->setStartTangentY(dLocStartTangentY);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocEndTangentX);
  if (iStat >= 0) osstDxf02TypHatchEdge->setEndTangentX(dLocEndTangentX);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &dLocEndTangentY);
  if (iStat >= 0) osstDxf02TypHatchEdge->setEndTangentY(dLocEndTangentY);

  *sErrTxt = oCsvRow.GetErrorString();

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
int sstDxf03FncHatchEdgeCls::Csv_Write(int iKey, sstDxf03TypHatchEdgeCls *poSstHatchEdge, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstHatchEdge->getRecordID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstHatchEdge->getParentID(), ssstDxfLib_Str);

  //  bool defined;
  //  int type;
  //  double x1;
  //  double y1;
  //  double x2;
  //  double y2;
  //  double cx;
  //  double cy;
  //  double radius;
  //  double angle1;
  //  double angle2;
  if (iStat >= 0) iStat = oCsvRow.Csv_Bool_2String( 0, poSstHatchEdge->getDefined(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Int2_2String( 0, poSstHatchEdge->getType(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getX1(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getY1(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getX2(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getY2(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getCx(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getCy(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getRadius(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getAngle1(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getAngle2(), ssstDxfLib_Str);

  //  bool ccw;
  //  double mx;
  //  double my;
  //  double ratio;
  //  unsigned int degree;
  //  bool rational;
  //  bool periodic;
  //  unsigned int nKnots;
  //  unsigned int nControl;
  //  unsigned int nFit;
  //  std::vector<std::vector<double> > controlPoints;
  //  std::vector<double> knots;
  //  std::vector<double> weights;
  //  std::vector<std::vector<double> > fitPoints;
  if (iStat >= 0) iStat = oCsvRow.Csv_Bool_2String( 0, poSstHatchEdge->getCcw(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getMx(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getMy(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getRatio(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, poSstHatchEdge->getDegree(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Bool_2String( 0, poSstHatchEdge->getRational(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Bool_2String( 0, poSstHatchEdge->getPeriodic(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, poSstHatchEdge->getNKnots(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, poSstHatchEdge->getNControl(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, poSstHatchEdge->getNFit(), ssstDxfLib_Str);

  //  double startTangentX;
  //  double startTangentY;
  //  double endTangentX;
  //  double endTangentY;
  //  std::vector<std::vector<double> > vertices;
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getStartTangentX(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getStartTangentY(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getEndTangentX(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Dbl_2String( 0, poSstHatchEdge->getEndTangentY(), ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf03FncHatchEdgeCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  //  bool defined;
  //  int type;
  //  double x1;
  //  double y1;
  //  double x2;
  //  double y2;
  //  double cx;
  //  double cy;
  //  double radius;
  //  double angle1;
  //  double angle2;
  //  bool ccw;
  //  double mx;
  //  double my;
  //  double ratio;
  //  unsigned int degree;
  //  bool rational;
  //  bool periodic;
  //  unsigned int nKnots;
  //  unsigned int nControl;
  //  unsigned int nFit;
  //  std::vector<std::vector<double> > controlPoints;
  //  std::vector<double> knots;
  //  std::vector<double> weights;
  //  std::vector<std::vector<double> > fitPoints;
  //  double startTangentX;
  //  double startTangentY;
  //  double endTangentX;
  //  double endTangentY;
  //  std::vector<std::vector<double> > vertices;

  oTitelStr = "RecordID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ParentID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "defined";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "type";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "x1";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "y1";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "x2";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "y2";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "cx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "cy";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "radius";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "angle1";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "angle2";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  bool defined;
  //  int type;
  //  double x1;
  //  double y1;
  //  double x2;
  //  double y2;
  //  double cx;
  //  double cy;
  //  double radius;
  //  double angle1;
  //  double angle2;

  oTitelStr = "ccw";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "mx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "my";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ratio";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "degree";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "rational";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "periodic";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "nKnots";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "nContol";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "nFit";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  bool ccw;
  //  double mx;
  //  double my;
  //  double ratio;
  //  unsigned int degree;
  //  bool rational;
  //  bool periodic;
  //  unsigned int nKnots;
  //  unsigned int nControl;
  //  unsigned int nFit;

  oTitelStr = "StartTangentX";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "StartTangentY";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "EndTangentX";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "EndTangentY";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  //  double startTangentX;
  //  double startTangentY;
  //  double endTangentX;
  //  double endTangentY;

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  return iStat;
}
//=============================================================================
int sstDxf03FncHatchEdgeCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf03TypHatchEdgeCls oSstArc;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstArc);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstArc,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf03FncHatchEdgeCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Insert to Csv file
  oCsvFilNam = oDxfFilNam + "_HatchEdge.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf03TypHatchEdgeCls oDxfHatchEdge;
    iStat = this->Read(0,kk,&oDxfHatchEdge);

    oDxfHatchEdge.setRecordID(kk);

    this->Csv_Write( 0, &oDxfHatchEdge, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
