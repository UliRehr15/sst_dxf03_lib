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
// sstDxf03EntityType.cpp    01.11.16  Re.    13.04.16  Re.
//
// Class handles librecad enum RS2::EntityType

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <list>

#include <dl_dxf.h>
#include <dl_creationadapter.h>

#include <rs.h>
#include <rs_vector.h>

#include <sstStr01Lib.h>
#include <sstMath01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf03Lib.h>

#include "sstDxf03LibInt.h"

//=============================================================================
sstDxf03EntityTypeCls::sstDxf03EntityTypeCls()
{

}
//=============================================================================
std::string sstDxf03EntityTypeCls::Enum2String(RS2::EntityType eType)
{
  std::string oLocString;
  switch (eType)
  {
    case RS2::EntityUnknown: oLocString = "Unknown"; break;
    case RS2::EntityContainer: oLocString = "Container"; break;
    case RS2::EntityBlock: oLocString = "Block"; break;
    case RS2::EntityFontChar: oLocString = "FontChar"; break;
    case RS2::EntityInsert: oLocString = "Insert"; break;
    case RS2::EntityGraphic: oLocString = "Graphic"; break;
    case RS2::EntityPoint: oLocString = "Point"; break;
    case RS2::EntityLine: oLocString = "Line"; break;
    case RS2::EntityPolyline: oLocString = "Polyline"; break;
    case RS2::EntityVertex: oLocString = "Vertex"; break;
    case RS2::EntityArc: oLocString = "Arc"; break;
    case RS2::EntityCircle: oLocString = "Circle"; break;
    case RS2::EntityEllipse: oLocString = "Ellipse"; break;
    case RS2::EntityHyperbola: oLocString = "Hyperbola"; break;
    case RS2::EntitySolid: oLocString = "Solid"; break;
    case RS2::EntityConstructionLine: oLocString = "ConstructionLine"; break;
    case RS2::EntityMText: oLocString = "MText"; break;
    case RS2::EntityText: oLocString = "Text"; break;
    case RS2::EntityDimAligned: oLocString = "DimAligned"; break;
    case RS2::EntityDimLinear: oLocString = "DimLinear"; break;
    case RS2::EntityDimRadial: oLocString = "DimRadial"; break;
    case RS2::EntityDimDiametric: oLocString = "DimDiametric"; break;
    case RS2::EntityDimAngular: oLocString = "DimAngular"; break;
    case RS2::EntityDimLeader: oLocString = "DimLeader"; break;
    case RS2::EntityHatch: oLocString = "Hatch"; break;
    case RS2::EntityHatchEdge: oLocString = "HatchEdge"; break;
    case RS2::EntityHatchLoop: oLocString = "HatchLoop"; break;
    case RS2::EntityImage: oLocString = "Image"; break;
    case RS2::EntitySpline: oLocString = "Spline"; break;
    case RS2::EntitySplinePoints: oLocString = "SplinePoints"; break;
    case RS2::EntityOverlayBox: oLocString = "OverlayBox"; break;
    case RS2::EntityPreview: oLocString = "Preview"; break;
    case RS2::EntityPattern: oLocString = "Pattern"; break;
  default: oLocString = "Unknown1"; break;
  }

  return oLocString;
}
//=============================================================================
RS2::EntityType sstDxf03EntityTypeCls::String2Enum(std::string oTypeString)
{
  RS2::EntityType eLocType;

  //  EntityUnknown,      /**< Unknown */
  //  EntityContainer,    /**< Container */
  //  EntityBlock,        /**< Block (Group definition) */
  //  EntityFontChar,     /**< Font character */
  //  EntityInsert,       /**< Insert (Group instance) */
  //  EntityGraphic,      /**< Graphic with layers */
  //  EntityPoint,        /**< Point */
  //  EntityLine,         /**< Line */
  //  EntityPolyline,     /**< Polyline */
  //  EntityVertex,       /**< Vertex (part of a polyline) */
  //  EntityArc,          /**< Arc */
  //  EntityCircle,       /**< Circle */
  //  EntityEllipse,      /**< Ellipse */
  //  EntityHyperbola,      /**< Hyperbola */
  //  EntitySolid,        /**< Solid */
  //  EntityConstructionLine, /**< Construction line */
  //  EntityMText,         /**< Multi-line Text */

  // int iStat = oTypeString.compare("Unknown");
  if (oTypeString.compare("Unknown") == 0) eLocType = RS2::EntityUnknown;
  else if (oTypeString.compare("Container") == 0) eLocType = RS2::EntityContainer;
  else if (oTypeString.compare("Block")     == 0) eLocType = RS2::EntityBlock;
  else if (oTypeString.compare("FontChar")  == 0) eLocType = RS2::EntityFontChar;
  else if (oTypeString.compare("Insert")    == 0) eLocType = RS2::EntityInsert;
  else if (oTypeString.compare("Graphic") == 0) eLocType = RS2::EntityGraphic;
  else if (oTypeString.compare("Point") == 0) eLocType = RS2::EntityPoint;
  else if (oTypeString.compare("Line") == 0) eLocType = RS2::EntityLine;
  else if (oTypeString.compare("Polyline") == 0) eLocType = RS2::EntityPolyline;
  else if (oTypeString.compare("Vertex") == 0) eLocType = RS2::EntityVertex;
  else if (oTypeString.compare("Arc") == 0) eLocType = RS2::EntityArc;
  else if (oTypeString.compare("Circle") == 0) eLocType = RS2::EntityCircle;
  else if (oTypeString.compare("Ellipse") == 0) eLocType = RS2::EntityEllipse;
  else if (oTypeString.compare("Hyperbola") == 0) eLocType = RS2::EntityHyperbola;
  else if (oTypeString.compare("Solid") == 0) eLocType = RS2::EntitySolid;
  else if (oTypeString.compare("ConstructionLine") == 0) eLocType = RS2::EntityConstructionLine;
  else if (oTypeString.compare("MText") == 0) eLocType = RS2::EntityMText;
  //  EntityText,         /**< Single-line Text */
  //  EntityDimAligned,   /**< Aligned Dimension */
  //  EntityDimLinear,    /**< Linear Dimension */
  //  EntityDimRadial,    /**< Radial Dimension */
  //  EntityDimDiametric, /**< Diametric Dimension */
  //  EntityDimAngular,   /**< Angular Dimension */
  //  EntityDimLeader,    /**< Leader Dimension */
  //  EntityHatch,        /**< Hatch */
  //  EntityImage,        /**< Image */
  //  EntitySpline,       /**< Spline */
  //  EntitySplinePoints,       /**< SplinePoints */
  //  EntityOverlayBox,    /**< OverlayBox */
  //  EntityPreview    /**< Preview Container */
  //,EntityPattern
  else if (oTypeString.compare("Text") == 0) eLocType = RS2::EntityText;
  else if (oTypeString.compare("DimAligned") == 0) eLocType = RS2::EntityDimAligned;
  else if (oTypeString.compare("DimLinear") == 0) eLocType = RS2::EntityDimLinear;
  else if (oTypeString.compare("DimRadial") == 0) eLocType = RS2::EntityDimRadial;
  else if (oTypeString.compare("DimDiametric") == 0) eLocType = RS2::EntityDimDiametric;
  else if (oTypeString.compare("DimAngular") == 0) eLocType = RS2::EntityDimAngular;
  else if (oTypeString.compare("DimLeader") == 0) eLocType = RS2::EntityDimLeader;
  else if (oTypeString.compare("Hatch") == 0) eLocType = RS2::EntityHatch;
  else if (oTypeString.compare("HatchEdge") == 0) eLocType = RS2::EntityHatchEdge;
  else if (oTypeString.compare("HatchLoop") == 0) eLocType = RS2::EntityHatchLoop;
  else if (oTypeString.compare("Image") == 0) eLocType = RS2::EntityImage;
  else if (oTypeString.compare("Spline") == 0) eLocType = RS2::EntitySpline;
  else if (oTypeString.compare("SplinePoints") == 0) eLocType = RS2::EntitySplinePoints;
  else if (oTypeString.compare("OverlayBox") == 0) eLocType = RS2::EntityOverlayBox;
  else if (oTypeString.compare("Preview") == 0) eLocType = RS2::EntityPreview;
  else if (oTypeString.compare("Pattern") == 0) eLocType = RS2::EntityPattern;
  else eLocType = RS2::EntityUnknown;

  //  EntityUnknown,      /**< Unknown */
  //  EntityContainer,    /**< Container */
  //  EntityBlock,        /**< Block (Group definition) */
  //  EntityFontChar,     /**< Font character */
  //  EntityInsert,       /**< Insert (Group instance) */
  //  EntityGraphic,      /**< Graphic with layers */
  //  EntityPoint,        /**< Point */
  //  EntityLine,         /**< Line */
  //  EntityPolyline,     /**< Polyline */
  //  EntityVertex,       /**< Vertex (part of a polyline) */
  //  EntityArc,          /**< Arc */
  //  EntityCircle,       /**< Circle */
  //  EntityEllipse,      /**< Ellipse */
  //  EntityHyperbola,      /**< Hyperbola */
  //  EntitySolid,        /**< Solid */
  //  EntityConstructionLine, /**< Construction line */
  //  EntityMText,         /**< Multi-line Text */
  //  EntityText,         /**< Single-line Text */
  //  EntityDimAligned,   /**< Aligned Dimension */
  //  EntityDimLinear,    /**< Linear Dimension */
  //  EntityDimRadial,    /**< Radial Dimension */
  //  EntityDimDiametric, /**< Diametric Dimension */
  //  EntityDimAngular,   /**< Angular Dimension */
  //  EntityDimLeader,    /**< Leader Dimension */
  //  EntityHatch,        /**< Hatch */
  //  EntityImage,        /**< Image */
  //  EntitySpline,       /**< Spline */
  //  EntitySplinePoints,       /**< SplinePoints */
  //  EntityOverlayBox,    /**< OverlayBox */
  //  EntityPreview    /**< Preview Container */
  //,EntityPattern

  return eLocType;
}
//=============================================================================

