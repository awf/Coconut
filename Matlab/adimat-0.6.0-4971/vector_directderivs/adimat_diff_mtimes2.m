function varargout = adimat_diff_mtimes2(varargin)
   varargout{1} = adimat_opdiff_mult_right(varargin{1:end});
end
% automatically generated from $Id: derivatives-vdd.xml 4891 2015-02-16 11:03:40Z willkomm $