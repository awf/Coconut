function varargout = adimat_diff_spdiags1(varargin)
   varargout{1} = call(@spdiags, varargin{1}, varargin{3});
end
% automatically generated from $Id: derivatives-vdd.xml 4891 2015-02-16 11:03:40Z willkomm $