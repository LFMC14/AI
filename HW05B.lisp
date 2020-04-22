; Developed by:
; Taha Hasan Syed
; Kyle Truong
; 


; Set values for actions based on index
(defvar A1 0)
(defvar A2 1)
(defvar A3 2)
(defvar actions '(A1 A2 A3))


; TERMINAL-TEST
(defun terminal-test(statelist)
  (cond
    ((equalp 'b (car (member 'b statelist)))
     nil)
    (t t)
  )
)


; UTILITY
(defun utility(statelist)
  (cond
    ((= (loop for state in statelist count (equalp 'a state)) 3)
     1)
    ((= (loop for state in statelist count (equalp 'c state)) 3)
     -1)
    (t 0)
  )
)


; ACTIONS
(defun actions(statelist)
  (loop for state in statelist
        for action in actions
        if (equalp 'b state)
        collect action
  )
)


; RESULT
(defun result(statelist action)
  (loop for state in statelist
        for i from 0 to 2
        if (equalp i action)
        collect 'A
        if (not (equalp i action))
        collect state
  )
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
(terpri)
(terpri)

; Testing ACTIONS
(write-line "Testing ACTIONS function")
(format t "(B C B) => ~S" (actions '(B C B)))
(terpri)
(format t "(A C B) => ~S" (actions '(A C B)))
(terpri)
(format t "(B B B) => ~S" (actions '(B B B)))
(terpri)
(format t "(A C C) => ~S" (actions '(A C C)))
(terpri)
(terpri)

; Testing RESULT
(write-line "Testing RESULT function")
(format t "(B C B), A3 => ~S" (result '(B C B) A3))
(terpri)
(format t "(A A A), A1 => ~S" (result '(A A A) A1))
(terpri)
(format t "(C B A), A2 => ~S" (result '(C B A) A2))
(terpri)
