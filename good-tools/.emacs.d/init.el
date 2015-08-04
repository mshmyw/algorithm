;; Added by Package.el.  This must come before configurations of
;; installed packages.  Don't delete this line.  If you don't want it,
;; just comment it out by adding a semicolon to the start of the line.
;; You may delete these explanatory comments.
(package-initialize)

;;; This file bootstraps the configuration, which is divided into
;;; a number of other files.
(when (version<= emacs-version "24")
  (message "Your Emacs is old, and some functionality in this config will be disabled. Please upgrade if possible."))

(add-to-list 'load-path (expand-file-name "lisp" user-emacs-directory))
(require 'init-benchmarking) ;; Measure startup time

;;----------------------------------------------------------------------------
;; Bootstrap config
;;----------------------------------------------------------------------------
(require 'init-compat)
(require 'init-utils)
;;(require 'init-site-lisp) ;; Must come before elpa, as it may provide package.el
(require 'init-elpa)      ;; Machinery for installing required packages
(require 'init-exec-path) ;; Set up $PATH

;;----------------------------------------------------------------------------
;; Load configs for specific features and modes
;;----------------------------------------------------------------------------

(require 'init-frame-hooks)
;; (require 'init-themes)
;; (require 'init-dired)
(require 'init-isearch)
(require 'init-grep)
(require 'init-ibuffer)
(require 'init-flycheck)

(require 'init-recentf)
;;(require 'init-ido)
(require 'init-hippie-expand)
(require 'init-auto-complete)

(require 'init-fonts)

(require 'init-editing-utils)
(require 'init-compile)
(require 'init-crontab)
(require 'init-markdown)
(require 'init-org)
(require 'init-python-mode)

(require 'init-paredit)
(require 'init-lisp)
(require 'init-slime)
(require 'init-misc)
(require 'init-xcscope)
(require 'init-dash)
(require 'init-ledger)
(require 'init-smart-compile)
(require 'init-hide-show)
(require 'init-window)
;;msh
(require 'init-multi-term)
(require 'init-cmake)
;; Extra packages which don't require any configuration

(require-package 'lua-mode)
(require 'init-unicad)

;;----------------------------------------------------------------------------
;; Allow access from emacsclient
;;----------------------------------------------------------------------------
(require 'server)
(unless (server-running-p)
  (server-start))

;;----------------------------------------------------------------------------
;; Variables configured via the interactive 'customize' interface
;;----------------------------------------------------------------------------
(setq custom-file (expand-file-name "custom.el" user-emacs-directory))
(when (file-exists-p custom-file)
  (load custom-file))


;;----------------------------------------------------------------------------
;; Allow users to provide an optional "init-local" containing personal settings
;;----------------------------------------------------------------------------
(when (file-exists-p (expand-file-name "init-local.el" user-emacs-directory))
  (error "Please move init-local.el to ~/.emacs.d/lisp"))
(require 'init-local nil t)

(add-hook 'after-init-hook
          (lambda ()
            (message "init completed in %.2fms"
                     (sanityinc/time-subtract-millis after-init-time before-init-time))))


(provide 'init)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages
   (quote
    (cmake yasnippet yari yaml-mode xcscope window-numbering window-number whole-line-or-region whitespace-cleanup-mode unfill undo-tree textile-mode tabbar switch-window smex smart-compile session scratch robe redshank rainbow-mode rainbow-delimiters pos-tip pip-requirements paredit-everywhere page-break-lines org-pomodoro org-fstree multiple-cursors multi-term move-dup mmm-mode markdown-mode macrostep lua-mode lively ledger-mode ipretty idomenu ido-ubiquitous ibuffer-vc hlinum hl-sexp hippie-expand-slime highlight-symbol highlight-quoted highlight-escape-sequences hideshowvis hideshow-org guide-key fuzzy fullframe flycheck-package flycheck-ledger fill-column-indicator expand-region exec-path-from-shell elisp-slime-nav dired-sort dired+ diminish diff-hl default-text-scale crontab-mode color-theme-sanityinc-tomorrow color-theme-sanityinc-solarized color-theme cmake-mode cl-lib-highlight browse-kill-ring autopair auto-complete-clang auto-compile anzu aggressive-indent ace-jump-mode ac-slime ac-math))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
;; Local Variables:
;; coding: utf-8
;; no-byte-compile: t
;; End:
