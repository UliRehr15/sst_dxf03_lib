# sst_dxf03_lib

sst_dxf03_lib stores dxf data in sst tables (sst_rec04_lib).
for every dxf entity type like ARC, MTEXT and so on there is a table.
this sst dxf tables could be stored in csv, so editing with spreedsheets
like excel is possible.

fork from sst_dxf01_lib: change license

change license to GNU General Public License version 2 because of use of LibreCAD.

Based on dxflib, extends dxflib
Uses functions from LibreCAD2

Compile with QT 5.5 and QTCreator 3.5

Structure of coding projects should be:

.. [libs]  <BR>
   [dxflib] from github <BR>
   [muParser]  <BR>
   [sstLibreCAD2Lib]  <BR>
   [sst_str01_lib]  <BR>
   [sst_misc01_lib]  <BR>
   [sst_rec04_lib]  <BR>
   [sst_dxf03_lib]  <BR>

28.02.16: Version 1.0: sst dxf lib: Tool Dxf2Csv: Realized: Layer Csv Table, Block Csv table, ARC Element Csv  <BR>
05.03.16: Version 1.1: Dxf2Csv: Arc Csv links to Layer Csv.  <BR>
05.03.16: Version 1.2: Dxf2Csv: Supports now INSERT element.  <BR>
10.03.16: Version 2.3: Change of Licence in according to librecad and dxflib. <BR>
                       Csv2Dxf: Tool frame and new table MAIN.  <BR>
29.04.16: Version 2.4: Tools Dxf2Csv and Csv2Dxf: Full support of ARC and INSERT.  <BR>
30.05.16: Version 2.5: Tool Dxf2Csv: Support of HATCH and POLYLINE.  <BR>
13.06.16: Version 2.6: Tool Csv2Dxf: Support of POLYLINE, extend support of attributes.  <BR>
17.06.16: Version 2.7: Tool Csv2Dxf: Support of HATCH.  <BR>
22.06.16: Version 2.8: General handling of layer/block data in entities.  <BR>
29.06.16: Version 2.9: Support for POLYLINE/HATCH in Block data.  <BR>
05.07.16: Version 2.10: Problems with color and width fixed.  <BR>
13.07.16: Version 2.11: new testframe for general testing.  <BR>
27.09.16: Version 2.12: Preparing works for entities circle, mtext, text. <BR>
21.10.16: Version 2.13: App Dxf2Csv: Full Support for circle, mtext, text. <BR>
28.10.16: Version 2.14: App Csv2Dxf: Full Support for circle, mtext, text. <BR>
                        Rise precision of decimal places to 4 for writing double values to csv <BR>
                        Caused by problems drawing filled circles in librecad. <BR>
25.11.16: Version 3.0: Redesign of user interface. hide implemetation details in library. <BR>
                       Support of entity types POINT and LINE. <BR>
                       Extent testframe with compare dxf after reading/writing. <BR>
23.12.16: Version 3.1: Support of entity types CIRCLE and HATCH. <BR>
21.05.17: Version 3.2: Add protocol events for import/export. <BR>
11.08.17: Version 3.3: Minimum Bounding Rectangle (Mbr)for dxf database. <BR>
23.02.18: Version 3.4: New function -ReadLINE-. <BR>
02.03.18: Version 3.5: New funktion -UpdateAttributesWithID. <BR>
09.03.18: Version 3.6: More Read-Functions for sstDxfDatabase.  <BR>
                       Calculate Mbr for block objects. <BR>
15.03.18: Version 3.7: New function -WriteLINE-. <BR>
18.03.18: Version 3.8: General functions -getMemberNames- for Type-Classes POINT, LINE, CIRCLE, MTEXT. <BR>
08.05.18: Version 3.9: Small improvements in Testframe and doxy help. <BR>
16.05.18: Version 3.10: Expand creating new dxf file with block infos and test writing/reading. <BR>
                        Fix error in function sstDxf03WriteCls::WrtSecBlocks. <BR>
25.05.18: Version 3.11: Extend entities in sstDxf03DatabaseCls::EntityCount. <BR>
13.06.18: Version 3.12: New entity D3Face. <BR>
25.06.18: Version 3.13: New entity Trace, lots of reads and writes for entities. <BR>
                        Added Type.def-File for sstDxf03. <BR>

