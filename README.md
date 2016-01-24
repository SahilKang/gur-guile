# gur-guile
Guile extension for libgur

```Scheme
(use-modules (gur-guile))

(define hello (gur-read 'a4 'e1 'h4 " " 'a4 'j2 'g2 'h5 " " 'a2 'b1 'h3 'g3))
  >"ਸਤਿ ਸ੍ਰੀ ਅਕਾਲ"

(define world (gur-read 'e3 'i1 'e5 'h5 'a2 'h3))
  >"ਦੁਨੀਅਾ"

(define hello-world (string-append hello " " world gur-q1))
  >"ਸਤਿ ਸ੍ਰੀ ਅਕਾਲ ਦੁਨੀਅਾ।"

(letters hello-world)
  >"ਸਤਸਰਅਕਲਦਨਅ"

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
