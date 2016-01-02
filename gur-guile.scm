(define-module (gur-guile)
  #:export (gur-read))

(load-extension "gur-guile.so" "scm_init_gur_guile_module")

(define (gur-read a . b)
  (let ((s ""))
    (let f ((x a) (y b))
      (unless (string? x) (set! x (primitive-eval (symbol-append 'gur- x))))
      (set! s (string-append s x))
      (unless (null? y) (f (car y) (cdr y))))
    s))
