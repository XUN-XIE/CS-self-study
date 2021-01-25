(define (abs x)
    (COND 
 ((< x 0) (- x))
 ((> x 0) x)
 ((= x 0) 0)
 )
)


(abs 1)
(abs (- 1))
(abs 0)
