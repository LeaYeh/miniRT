# Recalculations
camera change:
	ray_pool reset,	hit_record update,	cache_color update
	reset_ray_pool()	shoot_ray()		render_pixel()

object change:
					hit_record update,	cache_color update

light change:
										cache_color update

# Parsing
Need to allow tab bc in subject examples it also uses tab

# Events
- [X] Make light interactive.
- [X] Add support for scaling.
- [ ] Add support for color change.
- [ ] Pass rotation in full degrees so 90° can be easily counted.
- [X] Change to mode keys (C, O, L) to keep the keys consistent and also available on laptops.
- [X] Incorporate mouse.

# Todo
- [ ] Rename objects to object_list.
- [X] We don't do anything with ratio/brightness atm.
- [ ] Reset zoom.
- [X] Check if max values of subject should be checked in parsing.

# MLX functions
mlx_get_screen_size()
