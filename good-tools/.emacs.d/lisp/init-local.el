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

(provide 'init-local) ;;must have this 
