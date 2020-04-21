; Developed by:
; Taha Hasan Syed
;
;

(defun terminal-test(statlist)
   (if (member 'b statlist)
      (return-from terminal-test nil)
   (return-from terminal-test t)
   )
)

(defun utility(statlist)
   (if (= (loop for i in statlist count (equalp 'a i)) 3)
      (return-from utility 1)
   )
   
   (if (= (loop for i in statlist count (equalp 'c i)) 3)
      (return-from utility -1)
   )

   (return-from utility 0)
)

(defun actions(statlist)

)

(defun result()

)

;test cases to check if functions work
;test cases will be removed later as it is not a requirement in the assignment
(write-line "Testing terminal-test function")
(write-line "Terminal state: if a list contains no b's")
(write-line "Is the list(a b b) a terminal state?" )
(write (terminal-test (list 'a 'b 'b)))
(terpri)
(write-line "Is the list(a a a) a terminal state?")
(write (terminal-test (list 'a 'a 'a)))
(terpri)
(terpri)
(write-line "Testing utility function")
(write-line "List containing all a's:")
(write (utility (list 'a 'a 'a)))        
(terpri)
(write-line "List containing all c's:")
(write (utility (list 'c 'c 'c)))
(terpri)
(write-line "List containing any combinations:")
(write (utility (list 'a 'b 'c)))