P0 = [1 , 3]
P1 = [-1 , 2]
P2 = [2 , -1]
Pn = [P0 ; P1 ; P2]
xdata = [-2:.1:3]
x1=[1 , 2 , 3 ; 4, 5, 6 ; 7,8,9]
place = 3
nbPn = size(Pn , 1)
function affPoly(Pn)  
    X =[]
    Y =[]
    
    for i = 1:1:nbPn
        Y = [Y ; Pn(i,2)]
    end
    
    for i = 1:1:nbPn
        Pi = []
            for expo = 1:1:nbPn-1
               Pi = [Pi ,Pn(i , 1).^expo ]    
            end
            X = [X ; 1 , Pi]
    end
    
    C= inv(X)*Y
    Polynome  = poly(C , "x" , "c")
    
    plot(Pn(:,1), Pn(:,2), + "*b")
    plot (xdata , horner (Polynome, xdata ) , "r" )
endfunction

function interlagrange()
    L=0
    for j = 1:1:nbPn
        L=L + Pn(j,2)*lagrangepoly(Pn,j)
    end
    
    plot(Pn(:, 1), Pn(:, 2), + "*b")
    plot (xdata , horner (L, xdata ) , "r" )
   
endfunction

function [L] = lagrangepoly( x1, place)
        yv = poly(0 , "yv")
        nb= size(x1 , 1)
        L = 1
        
        for i =1:nb
            if(i<> place) then
                A = (yv-x1(i , 1))/(x1(place , 1)-x1(i , 1))
                L*A
            end
        end
        
endfunction

function exo()
    PnTrie = gsort(Pn,'lr' , 'i') 
    
    X = []
    Y = []
    
for i=1:1:nbPn
        X = [X , PnTrie(i ,1)]
        Y = [Y , PnTrie(i, 2)]   
    end
    
    
    spline=smooth([X ; Y], 0.1)

    plot (Pn(:, 1), Pn(:, 2), "+r")
    plot (spline(1, :), spline(2, :))
endfunction
