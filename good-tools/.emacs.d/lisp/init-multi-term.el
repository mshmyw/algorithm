(require-package 'multi-term)
(require 'multi-term)

(setq multi-term-program "/bin/bash")

(add-hook 'term-mode-hook
          (lambda ()
            (setq term-buffer-maximum-size 0)))

(add-hook 'term-mode-hook

          (lambda ()

            (define-key term-raw-map (kbd "C-y") 'term-paste)))

(add-hook 'term-mode-hook
          (lambda ()
            (add-to-list 'term-bind-key-alist '("M-[" . multi-term-prev))
            (add-to-list 'term-bind-key-alist '("M-]" . multi-term-next))))


(defadvice multi-term (after advice-term-line-mode activate)
  (term-line-mode))

(provide 'init-multi-term)
