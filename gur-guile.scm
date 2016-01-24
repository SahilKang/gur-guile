;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ; Copyright (C) 2015, 2016 Sahil Singh Kang <sahil.kang@asilaycomputing.com>
 ;
 ; This file is part of gur-guile.
 ;
 ; gur-guile is free software: you can redistribute it and/or modify
 ; it under the terms of the GNU Affero General Public License as published by
 ; the Free Software Foundation, either version 3 of the License, or
 ; (at your option) any later version.
 ;
 ; gur-guile is distributed in the hope that it will be useful,
 ; but WITHOUT ANY WARRANTY; without even the implied warranty of
 ; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ; GNU Affero General Public License for more details.
 ;
 ; You should have received a copy of the GNU Affero General Public License
 ; along with gur-guile.  If not, see <http://www.gnu.org/licenses/>.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define-module (gur-guile)
  #:export (gur-read))

(load-extension "gur-guile.so" "scm_init_gur_guile_module")

(define (gur-read a . b)
  (define (resolve x)
    (if (string? x)
        x
	(primitive-eval (symbol-append 'gur- x))))
  (let loop ((x a) (y b) (s ""))
    (if (null? y)
        (string-append s (resolve x))
	(loop (car y) (cdr y) (string-append s (resolve x))))))
