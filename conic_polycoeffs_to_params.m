"""
    drwc_par2geom(par)

Convert [Axx Axy Ayy Ax Ay Ao] conic to [cx cy rx ry theta].
"""
function drwc_par2geom(par)

# Author: Andrew Fitzgibbon, Edinburgh University AI Dept.
# Email: andrewfg@ed.ac.uk
# Date: 04 Apr 96

if nargin < 1
  %% test
  c = [.1 .3 .5 .7 31];
  p = drwc_geom2par(c);
  au_test_equal drwc_par2geom(p) c 1e-8
  return
end

Axx = par[:,1]
Axy = par[:,2]
Ayy = par[:,3]
Ax  = par[:,4]
Ay  = par[:,5]
Ao  = par[:,6]

thetarad = 0.5*atan2(Axy ,Axx - Ayy);
cost = cos(thetarad);
sint = sin(thetarad);
sin_squared = sint.*sint;
cos_squared = cost.*cost;
cos_sin = sint .* cost;

#Ao = par(:,1);
Au =   par(:,2) .* cost + par(:,3) .* sint;
Av = - par(:,2) .* sint + par(:,3) .* cost;
Auu = par(:,4) .* cos_squared + par(:,5) .* sin_squared + par(:,6) .* cos_sin;
Avv = par(:,4) .* sin_squared + par(:,5) .* cos_squared - par(:,6) .* cos_sin;

% ROTATED = [Ao Au Av Auu Avv]

tuCentre = - Au./(2.*Auu);
tvCentre = - Av./(2.*Avv);
wCentre = Ao - Auu.*tuCentre.*tuCentre - Avv.*tvCentre.*tvCentre;

uCentre = tuCentre .* cost - tvCentre .* sint;
vCentre = tuCentre .* sint + tvCentre .* cost;

Ru = -wCentre./Auu;
Rv = -wCentre./Avv;

Ru = sqrt(abs(Ru)).*sign(Ru);
Rv = sqrt(abs(Rv)).*sign(Rv);

geom = [uCentre, vCentre, Ru, Rv, thetarad * (180/pi)];
