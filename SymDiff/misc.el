
;;; (replace-nth '(a0 a1 a2 a3) 2 'NEW) -> (a0 a1 NEW a3) 
(defun replace-nth (list n newval)
  (if (= n 0)
      (cons newval (cdr list))
    (cons (car list) (replace-nth (cdr list) (- n 1) newval))))

(ert-deftest replace-nth-test ()
  (let* ((lst '(a0 a1 a2 a3 a4)))
    (should (equal (replace-nth lst 2 'zz2) '(a0 a1 zz2 a3 a4)))))

;;; (replace-eq '(a0 a1 a2 a3) 'a2 'NEW) -> (a0 a1 NEW a3) 
(defun replace-eq (list oldval newval)
  (if (eq (car list) oldval)
      (cons newval (cdr list))
    (cons (car list) (replace-eq (cdr list) oldval newval))))

(ert-deftest replace-nth-test ()
  (let* ((lst '(a000 a111 a222 a333 a444)))
    (should (equal (replace-eq lst 'a222 'z222) '(a000 a111 z222 a333 a444)))))

;;; make-zipper
(defun make-zipper (focus context)
  (cons focus context))

(defun get-focus (zipper)
  (car zipper))

(defun get-context (zipper)
  (cdr zipper))

(ert-deftest zipper ()
  (should (equal (get-focus (make-zip 1 2)) 1))
  (should (equal (get-context (make-zip 1 2)) 2))
  )
  

;;; (go-to-child (n zipper))
;; return a new zipper visiting the nth child of the given zipper
;; cost is roughly that of a shallow copy (to depth 1) of the current focus
(defun go-to-child (n zipper)
  (let* ((focus (car zipper))
	 (context (cdr zipper))
	 (child (nth n focus))
	 (newfocus child)
	 (newcontext (cons (replace-nth focus n '*hole*) context))
	 )
    (make-zipper newfocus newcontext)))

(defun go-to-parent (zipper)
  (let* ((focus (car zipper))
	 (context (cdr zipper))
	 (newfocus (replace-eq (car context) '*hole* focus))
	 (newcontext (cdr context))
	 )
    (make-zipper newfocus newcontext)))

(ert-deftest zipper-traversal ()
  (let* (
	 (tree '(% (/ (- d e) (+ a (* b c))) (+ f g)))
	 (zipper (make-zipper tree nil)) ; (focus . context)
	 
	 )
    
    (pp tree)

    ;; move down
    (let* ((downdown (go-to-child 1 (go-to-child 1 zipper)))
	   (upup (go-to-parent (go-to-parent downdown))))
      (should (equal upup zipper))
      (should-f
      downdown)
    ))

(ert t)

			   
