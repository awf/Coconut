function varargout = adimat_diff_sum1(varargin)
   varargout{1} = sum(varargin{1}, adimat_first_nonsingleton(varargin{2}) + 1);
end
% automatically generated from $Id: derivatives-vdd.xml 4891 2015-02-16 11:03:40Z willkomm $