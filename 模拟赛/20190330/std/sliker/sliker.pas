type v=longint;
var mp,num,o,ma:array[0..51,0..51]of v;
    x,y:array[0..1000000]of v;
    c:char;
    n,m,i,j,head,tail,ksx,ksy,enx,eny:v;
function min(x,y:v):v;
begin
  if x<y then exit(x);
  exit(y);
end;
begin
  assign(input,'sliker.in');
  assign(output,'sliker.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  fillchar(num,sizeof(num),22);
  for i:=0 to n+1 do
    begin
      mp[i,0]:=2;
      mp[i,m+1]:=2;
    end;
  for i:=0 to m+1 do
    begin
      mp[0,i]:=2;
      mp[n+1,i]:=2;
    end;
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(c);
          if(c='D')or(c='d')then
            begin
              mp[i,j]:=4;
              enx:=i;
              eny:=j;
            end;
          if(c='*')then
            begin
              mp[i,j]:=3;
              inc(tail);
              x[tail]:=i;
              y[tail]:=j;
              num[i,j]:=0;
            end;
          if(c='X')or(c='x')then mp[i,j]:=2;
          if(c='S')or(c='s')then
            begin
              mp[i,j]:=1;
              ksx:=i;
              ksy:=j;
            end;
        end;
      readln;
    end;
  ma:=mp;
  head:=1;
  while head<=tail do
    begin
      if(mp[x[head]-1,y[head]]=0){or(mp[x[head]-1,y[head]]=4)}or(mp[x[head]-1,y[head]]=1)then
        begin
          num[x[head]-1,y[head]]:=min(num[x[head],y[head]]+1,num[x[head]-1,y[head]]);
          mp[x[head]-1,y[head]]:=5;
          tail:=tail+1;
          x[tail]:=x[head]-1;
          y[tail]:=y[head];
        end;
      if(mp[x[head]+1,y[head]]=0){or(mp[x[head]+1,y[head]]=4)}or(mp[x[head]+1,y[head]]=1)then
        begin
          num[x[head]+1,y[head]]:=min(num[x[head],y[head]]+1,num[x[head]+1,y[head]]);
          mp[x[head]+1,y[head]]:=5;
          tail:=tail+1;
          x[tail]:=x[head]+1;
          y[tail]:=y[head];
        end;
      if(mp[x[head],y[head]+1]=0){or(mp[x[head],y[head]+1]=4)}or(mp[x[head],y[head]+1]=1)then
        begin
          num[x[head],y[head]+1]:=min(num[x[head],y[head]]+1,num[x[head],y[head]+1]);
          mp[x[head],y[head]+1]:=5;
          tail:=tail+1;
          x[tail]:=x[head];
          y[tail]:=y[head]+1;
        end;
      if(mp[x[head],y[head]-1]=0){or(mp[x[head],y[head]-1]=4)}or(mp[x[head],y[head]-1]=1)then
        begin
          num[x[head],y[head]-1]:=min(num[x[head],y[head]]+1,num[x[head],y[head]-1]);
          mp[x[head],y[head]]:=5;
          tail:=tail+1;
          x[tail]:=x[head];
          y[tail]:=y[head]-1;
        end;
      head:=head+1;
    end;
  num[enx,eny]:=100000000;
  head:=1;
  tail:=1;
  x[1]:=ksx;
  y[1]:=ksy;
  while head<=tail do
    begin
      if((ma[x[head]-1,y[head]]=0)or(ma[x[head]-1,y[head]]=4)or(ma[x[head]-1,y[head]]=1))and(num[x[head]-1,y[head]]>o[x[head],y[head]]+1)then
        begin
          o[x[head]-1,y[head]]:=o[x[head],y[head]]+1;
          ma[x[head]-1,y[head]]:=5;
          tail:=tail+1;
          x[tail]:=x[head]-1;
          y[tail]:=y[head];
        end;
      if((ma[x[head]+1,y[head]]=0)or(ma[x[head]+1,y[head]]=4)or(ma[x[head]+1,y[head]]=1))and(num[x[head]+1,y[head]]>o[x[head],y[head]]+1)then
        begin
          o[x[head]+1,y[head]]:=o[x[head],y[head]]+1;
          ma[x[head]+1,y[head]]:=5;
          tail:=tail+1;
          x[tail]:=x[head]+1;
          y[tail]:=y[head];
        end;
      if((ma[x[head],y[head]+1]=0)or(ma[x[head],y[head]+1]=4)or(ma[x[head],y[head]+1]=1))and(num[x[head],y[head]+1]>o[x[head],y[head]]+1)then
        begin
          o[x[head],y[head]+1]:=o[x[head],y[head]]+1;
          ma[x[head],y[head]+1]:=5;
          tail:=tail+1;
          x[tail]:=x[head];
          y[tail]:=y[head]+1;
        end;
      if((ma[x[head],y[head]-1]=0)or(ma[x[head],y[head]-1]=4)or(ma[x[head],y[head]-1]=1))and(num[x[head],y[head]-1]>o[x[head],y[head]]+1)then
        begin
          o[x[head],y[head]-1]:=o[x[head],y[head]]+1;
          ma[x[head],y[head]]:=5;
          tail:=tail+1;
          x[tail]:=x[head];
          y[tail]:=y[head]-1;
        end;
      head:=head+1;
    end;
  if o[enx,eny]>0 then write(o[enx,eny])
  else write('ORZ hzwer!!!');
  close(input);
  close(output);
end.