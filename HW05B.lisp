(defun terminal-test(statlist)
   (if (member 'b statlist)
      (return-from terminal-test t)
   (return-from terminal-test nil)
   )
)

(defun utility(statlist)

)

(defun actions(statlist)

)

(defun result()

)

(write (terminal-test (list 'a 'a 'a)))