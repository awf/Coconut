% Generated by ADiMat 0.6.0-4728
% Copyright 2009-2013 Johannes Willkomm, Fachgebiet Scientific Computing,
% TU Darmstadt, 64289 Darmstadt, Germany
% Copyright 2001-2008 Andre Vehreschild, Institute for Scientific Computing,
% RWTH Aachen University, 52056 Aachen, Germany.
% Visit us on the web at http://www.adimat.de
% Report bugs to adimat-users@lists.sc.informatik.tu-darmstadt.de
%
%
%                             DISCLAIMER
%
% ADiMat was prepared as part of an employment at the Institute
% for Scientific Computing, RWTH Aachen University, Germany and is
% provided AS IS. NEITHER THE AUTHOR(S), THE GOVERNMENT OF THE FEDERAL
% REPUBLIC OF GERMANY NOR ANY AGENCY THEREOF, NOR THE RWTH AACHEN UNIVERSITY,
% INCLUDING ANY OF THEIR EMPLOYEES OR OFFICERS, MAKES ANY WARRANTY,
% EXPRESS OR IMPLIED, OR ASSUMES ANY LEGAL LIABILITY OR RESPONSIBILITY
% FOR THE ACCURACY, COMPLETENESS, OR USEFULNESS OF ANY INFORMATION OR
% PROCESS DISCLOSED, OR REPRESENTS THAT ITS USE WOULD NOT INFRINGE
% PRIVATELY OWNED RIGHTS.
%
% Global flags were:
% FORWARDMODE -- Apply the forward mode to the files.
% NOOPEROPTIM -- Do not use optimized operators. I.e.:
%		 g_a*b*g_c -/-> mtimes3(g_a, b, g_c)
% NOLOCALCSE  -- Do not use local common subexpression elimination when
%		 canonicalizing the code.
% NOGLOBALCSE -- Prevents the application of global common subexpression
%		 elimination after canonicalizing the code.
% NOPRESCALARFOLDING -- Switch off folding of scalar constants before
%		 augmentation.
% NOPOSTSCALARFOLDING -- Switch off folding of scalar constants after
%		 augmentation.
% NOCONSTFOLDMULT0 -- Switch off folding of product with one factor
%		 being zero: b*0=0.
% FUNCMODE    -- Inputfile is a function (This flag can not be set explicitly).
% NOTMPCLEAR  -- Suppress generation of clear g_* instructions.
% UNBOUND_XML  -- Write list of unbound identifiers in XML format.
% DEPENDENCIES_XML  -- Write list of functions in XML format.
% UNBOUND_ERROR	-- Stop with error if unbound identifiers found (default).
% FUNCTION_LIST_XML	-- Write list of functions to XML file.
% VERBOSITYLEVEL=5
% AD_IVARS= x, c
% AD_DVARS= r


function [g_r, r]= g_example1(g_x, x, g_c, c)
   r= 0; 
   g_r= g_zeros(size(r));
   powerOfX= 1; 
   g_powerOfX= g_zeros(size(powerOfX));
   for i= 1: length(c)
      g_tmp_c_00000= g_c(i);
      tmp_c_00000= c(i);
      g_tmp_example1_00000= g_tmp_c_00000* powerOfX+ tmp_c_00000* g_powerOfX;
      tmp_example1_00000= tmp_c_00000* powerOfX;
      g_tmp_example1_00001= g_r+ g_tmp_example1_00000;
      tmp_example1_00001= r+ tmp_example1_00000; 
      % Update detected: r= some_expression(r,...)
      g_r= g_tmp_example1_00001;
      r= tmp_example1_00001;
      g_tmp_example1_00002= g_powerOfX* x+ powerOfX* g_x;
      tmp_example1_00002= powerOfX* x; 
      % Update detected: powerOfX= some_expression(powerOfX,...)
      g_powerOfX= g_tmp_example1_00002;
      powerOfX= tmp_example1_00002;
   end
   
end