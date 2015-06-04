(require-package 'hideshowvis)
(require 'hideshowvis)

(require-package 'hideshow-org)  ;;another +/- code-folding
(require 'hideshow-org)

(global-set-key "\C-ch" 'hs-org/minor-mode)

(autoload 'hideshowvis-enable "hideshowvis" "Highlight foldable regions")

(autoload 'hideshowvis-minor-mode
  "hideshowvis"
  "Will indicate regions foldable with hideshow in the fringe."
  'interactive)


(dolist (hook (list 'emacs-lisp-mode-hook
                    'c++-mode-hook
                    'c-mode-hook))
  (add-hook hook 'hideshowvis-enable))

(hideshowvis-symbols)

(provide 'init-hide-show)
