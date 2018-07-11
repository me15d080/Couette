% parameters
UI=load ("/home/vikas/Desktop/Couette_flow/input/user_input");
Lx=UI(1);
Ly=UI(2);
nx=UI(7);
ny=UI(8);
nsteps=UI(10);
% create quiver grid
XQ=linspace(0 ,Lx,nx+1);YQ=linspace(Ly,0 ,ny+1);
[xq,yq]=meshgrid(XQ,YQ);
% avg velocity components
uavg=0*xq;
vavg=0*xq;
% start the loop
for k = 1:nsteps
% read the output files
  file1  = sprintf('/home/vikas/Desktop/Couette_flow/output/%d/p', k);
  p_data = importdata(file1);
  file2  = sprintf('/home/vikas/Desktop/Couette_flow/output/%d/u', k);
  u_data = importdata(file2);
  file3  = sprintf('/home/vikas/Desktop/Couette_flow/output/%d/v', k);
  v_data = importdata(file3);
% convert to matrix format
  p=zeros(ny+1, nx+1);for i=1:ny+1;for j=1:nx+1;p(i,j)=p_data(j+(nx+1)*(i-1));end end
  u=zeros(ny+1, nx+2);for i=1:ny+1;for j=1:nx+2;u(i,j)=u_data(j+(nx+2)*(i-1));end end
  v=zeros(ny+2, nx+3);for i=1:ny+2;for j=1:nx+3;v(i,j)=v_data(j+(nx+3)*(i-1));end end
% velocity vector plot
  uavg(1:ny+1,1:nx+1)=0.5*(u(1:ny+1,1:nx+1)+u(1:ny+1,2:nx+2));
  vavg(1:ny+1,1:nx+1)=0.5*(v(1:ny+1,2:nx+2)+v(2:ny+2,2:nx+2));
  quiver(xq,yq,uavg,vavg,'r');
  axis equal,
  axis([0 Lx 0 Ly]);
  drawnow

end
