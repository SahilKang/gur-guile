# gur-guile
Guile extension for libgur

```Scheme
(use-modules (gur-guile))

(define hello (string-append gur-a4 gur-e1 gur-h4 " " gur-a4 gurj2 gur-h5 " " gur-a2 gur-b1 gur-h3 gur-g3))
  >"ਸਤਿ ਸ੍ੀ ਅਕਾਲ"

(define world (string-append gur-e3 gur-i1 gur-e5 gur-h5 gur-a2 gur-h3))
  >"ਦੁਨੀਅਾ"

(define hello-world (string-append hello " " world gur-q1))
  >"ਸਤਿ ਸ੍ੀ ਅਕਾਲ ਦੁਨੀਅਾ।"

(letters hello-world)
  >"ਸਤਸਅਕਲਦਨਅ"

(string->list (accents hello-world))
  >("ਿ", "ੀ", "੍", "ਾ", "ੁ", "ੀ", "ਾ")

(puncs hello-world)
  >"।"

(string->list (comp hello-world))
  >("ਅ", "ਸ", "ਕ", "ਤ", "ਦ", "ਨ", "ਲ", "ਾ", "ਿ", "ੀ", "ੁ", "੍", "।", " ")

(string->list world)
  >("ਦ", "ੁ", "ਨ", "ੀ", "ਅ", "ਾ")

(string->list (clobber world))
  >("ਦ", "ੁ", "ਨ", "ੀ", "ਆ")
```
