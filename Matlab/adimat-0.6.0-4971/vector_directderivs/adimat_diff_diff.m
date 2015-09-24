function varargout = adimat_diff_diff(varargin)
   varargout{1} =   d_zeros(diff(varargin{2}, varargin{3:end}));
    szx = size(varargin{2});
    for i=1:size(varargin{1}, 1)
      dd = diff(reshape(varargin{1}(i, :), szx), varargin{3:end});
      varargout{1}(i, :) = dd(:).';
    end
      ;
end
% automatically generated from $Id: derivatives-vdd.xml 4891 2015-02-16 11:03:40Z willkomm $