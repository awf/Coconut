function out = Q(q, l, v)

if nargin == 0
  Qtimesv([0.1 -1.0 0.3],[5.0 -2.0 7.1], [5.0 -2.0 7.1])
  return 
end

d = length(q);
Q = diag(exp(q));
row = 2;
col = 1;
for k = 1:length(l)
  Q(row, col) = l(k);
  col = col + 1;
  if col == row
    row = row + 1;
    col = 1;
  end
end
au_assert_equal row d+1
au_assert_equal col 1

out= Q * v(:);
