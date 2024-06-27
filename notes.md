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
