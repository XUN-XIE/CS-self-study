(DEFINE A (+ 1 1))
(+ A A A)

(define (square x) (* x x))
(square A)

(define square2 
    (lambda (x) (* x x)))
(square A)

