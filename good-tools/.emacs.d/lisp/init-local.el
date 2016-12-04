(setq inhibit-startup-message 0)

;;fullscreen
(global-set-key (kbd "<f11>") 'toggle-frame-fullscreen)
(toggle-frame-fullscreen) ;;full-screen


(tool-bar-mode 0)
(menu-bar-mode 1)

(scroll-bar-mode 0)

(setq frame-title-format "%b@Msh-UESTC")

(setq x-select-enable-clipboard t)

;; * date
(setq   system-time-locale "C"
        display-time-format "%Y-%m-%d %a %H:%M:%S"
        display-time-day-and-date t
        display-time-24hr-format t
        display-time-interval 1)
(display-time-mode t)               

(if window-system
    (setq default-frame-alist
          (append
           '( (top . 32)
              (left . 100)
              (width . 80)
              (height . 24))
           default-frame-alist))
  )


(mouse-avoidance-mode 'animate)

(blink-cursor-mode -1)

(transient-mark-mode 1)

(show-paren-mode 1)

(mouse-wheel-mode t)

(column-number-mode t)
(require 'linum)
(global-linum-mode 1)

(show-paren-mode t)
(setq show-paren-style 'parentheses)

(global-font-lock-mode t)
(setq font-lock-maximum-decoration t)

(require 'hl-line)
(global-hl-line-mode t)
(global-font-lock-mode 1)


(setq default-tab-width 4)
(setq c-basic-offset 4)


;; comment for c and other language
(global-set-key [?\C-c ?\C-/] 'comment-or-uncomment-region)
(defun my-comment-or-uncomment-region (beg end &optional arg)
  (interactive (if (use-region-p)
                   (list (region-beginning) (region-end) nil)
                 (list (line-beginning-position)
                       (line-beginning-position 2))))
  (comment-or-uncomment-region beg end arg)
  )
(global-set-key [remap comment-or-uncomment-region] 'my-comment-or-uncomment-region)

(global-set-key (kbd "<f8>") 'multi-term)
(require 'tabbar)  ;;show tabbar mode
(tabbar-mode)
(global-set-key (kbd "C-c b") 'tabbar-backward-group)   ;;backward shortcut key
(global-set-key (kbd "C-c f") 'tabbar-forward-group)   ;;forward shortcut key
(global-set-key (kbd "C-,") 'tabbar-backward)
(global-set-key (kbd "C-.") 'tabbar-forward)

;;auto insert
;;首先这句话设置一个目录，你的auto-insert 的模版文件会存放在这个目录中，
(setq-default auto-insert-directory "~/.emacs.d/auto-insert/")
(auto-insert-mode)  ;;; 启用auto-insert
;; 默认情况下插入模版前会循问你要不要自动插入，这里设置为不必询问，
;; 在新建一个org文件时，自动插入`auto-insert-directory'目录下的`org-auto-insert`文件中的内容
(setq auto-insert-query nil) 
(define-auto-insert "\\.org" "org-auto-insert")
;;这个就是新建以.c 结尾的C文件时，会自动插入c-auto-insert文件中的内容
(define-auto-insert "\\.c" "c-auto-insert")
;;cpp template
(define-auto-insert "\\.cpp" "cpp-auto-insert")
;;makefile template
(define-auto-insert "\\file" "Makefile-auto-insert")

(defadvice auto-insert  (around yasnippet-expand-after-auto-insert activate)
  "expand auto-inserted content as yasnippet templete,
  so that we could use yasnippet in autoinsert mode"
  (let ((is-new-file (and (not buffer-read-only)
                          (or (eq this-command 'auto-insert)
                              (and auto-insert (bobp) (eobp))))))
    ad-do-it
    (let ((old-point-max (point-max)))
      (when is-new-file
        (goto-char old-point-max)
        (yas-expand-snippet (buffer-substring-no-properties (point-min) (point-max)))
        (delete-region (point-min) old-point-max)
        )
      )
    )
  )

(window-numbering-mode 1)

;;在Emacs中激活GPG的加密功能, the file must end with ".gpg"
(require 'epa-file)

;;使用对称加密的方法, close the asymmetric way
;;(setq epa-file-select-keys 0)

;; set default coding system
(setq utf-translate-cjk-mode nil) ; disable CJK coding/encoding (Chinese/Japanese/Korean characters)
(set-language-environment 'utf-8)
(set-keyboard-coding-system 'utf-8-mac) ; For old Carbon emacs on OS X only
(setq locale-coding-system 'utf-8)
(set-default-coding-systems 'utf-8)
(set-terminal-coding-system 'utf-8)
(unless (eq system-type 'windows-nt)
  (set-selection-coding-system 'utf-8))
(prefer-coding-system 'utf-8)

;;set tabbar face: color, size
(set-face-attribute 'tabbar-selected nil  
                    :inherit 'tabbar-default  
                    :foreground "DarkGreen"  
                    :background "LightGoldenrod"  
                    :box '(:line-width 2 :color "DarkGoldenrod")  
                    :overline "black"  
                    :underline "black"  
                    :weight 'bold  
                    )

(provide 'init-local) ;;must have this 
