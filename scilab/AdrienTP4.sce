P1=[1 3];
P2=[-1 2];
P3=[2 -1];
Ps=[P1;P2;P3];
function interpol(Ps)
    xdata= [-2:.1:3];
    nbrPs= size(Ps, 1);
    
    X=[];
    Y=[];
    
    for i=1:1:nbrPs
        Y= [Y;Ps(i,2)];
    end
    
    for i=1:1:nbrPs
        pi=[]
            for expo=1:1:nbrPs-1
                pi=[pi,Ps(i,1)^expo]; 
            end
        X= [X;1,pi];
    end
    
    C=inv(X)*Y;
    polynome=poly(C,"x","c")
    plot(Ps(:,1),Ps(:,2),+"*r")
    plot(xdata,horner(polynome,xdata),"g")   
endfunction

function interpolLagrange()
    xdata= [-2:.1:3];
    nbrPs=size(Ps,1)
    L=0;
    for i=1:1:nbrPs
        L=L+Ps(i,2)*lagrangePoly(Ps,i);
    end
    plot(Ps(:,1),Ps(:,2),+"*r");
    plot(xdata,horner(L,xdata),"r");
endfunction

function [L]=lagrangePoly(X,rang)
    P=poly(0,"P");
    nbr=size(X,1);
    L=1;
    for i =1:nbr
        if(i<> rang) then
            A = (P-X(i , 1))/(X(rang , 1)-X(i , 1))
            L*A
        end
    end
endfunction    

function ex4()
    xdata= [-2:.1:3];
    PsTri=gsort(Ps,'lr','i');
    nbrPs=size(Ps,1);
    X=[];
    Y=[];
    
    for i=1:1:nbrPs
        X=[X,PsTri(i,1)];
        Y=[Y,PsTri(i,2)];
    end
    
    spline=smooth([X ; Y], 0.1);

    plot(Ps(:, 1), Ps(:, 2), "+r");
    plot(spline(1, :), spline(2, :));
    
endfunction

