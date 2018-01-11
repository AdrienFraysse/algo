P0 = [1 , 3]
P1 = [-1 , 2]
P2 = [2 , -1]
Pn = [P0 ; P1 ; P2]
function affPoly(Pn)
  
    xdata = [-2:.1:3]
    nbPn = size(Pn , 1)
    
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
    Polynome  = poly(C, "x", "c")
    
    plot(Pn(:,1), Pn(:,2), + "*b")
    plot (X, Y, "+r " , xdata , horner (Polynome, xdata ) , "r" ) ;
    
    
endfunction
