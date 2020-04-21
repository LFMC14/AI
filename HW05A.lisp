(defvar a)
(defvar b)
(setq a '(w x y z))
(setq b '(2 4 6 8))

;(z y x w)
(format t "~%")      ; new line
(write (reverse a))  ; reverse the list

;(14 y (x 4))
(format t "~%") 
(setq c (+ (car (member 6 b))(car (member 8 b))))  ; Assign arithmetic value to a variable 'c'
(write (list                                ;(14 y)
            c 
            (car (member 'y a)) 
            (list                           ;(x 4)
                (car (member 'x a)) 
                (car (member 4 b)))
        )
)

;((w x y z) . 2)
(format t "~%") 
(write (cons a (car b)))

;(((w y) (2 4)) . w)
(format t "~%") 
(write (cons 
            (list 
                (list 
                    (car  a) 
                    (car (member 'y a))) 
                (list 
                    (car b) 
                    (car (member 4 b)))) 

            (car a)
        )
)

;((w 2) (x 4) (y 6) (z 8))
(format t "~%") 
(write (list 
            (list                           ;(w 2)
                (car a) 
                (car b)) 
            (list                           ;(x 4)
                (car (member 'x a)) 
                (car (member 4 b)))
            (list                           ;(y 6)
                (car (member 'y a)) 
                (car (member 6 b)))  
            (append                          ;(z 8)
                (last a) 
                (last b)
            )
        )
)