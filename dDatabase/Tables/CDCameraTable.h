#pragma once
#include "CDTable.h"

//Generated by xmlDb2dDatabaseGenerator on 2022-03-04 00:23:32.907075
//DO NOT EDIT THIS FILE MANUALLY!

struct CDCamera {
	std::string camera_name;
	float pitch_angle_tolerance;
	float starting_zoom;
	float zoom_return_modifier;
	float pitch_return_modifier;
	float tether_out_return_modifier;
	float tether_in_return_multiplier;
	float verticle_movement_dampening_modifier;
	float return_from_incline_modifier;
	float horizontal_return_modifier;
	float yaw_behavior_speed_multiplier;
	float camera_collision_padding;
	float glide_speed;
	float fade_player_min_range;
	float min_movement_delta_tolerance;
	float min_glide_distance_tolerance;
	float look_forward_offset;
	float look_up_offset;
	float minimum_vertical_dampening_distance;
	float maximum_vertical_dampening_distance;
	float minimum_ignore_jump_distance;
	float maximum_ignore_jump_distance;
	float maximum_auto_glide_angle;
	float minimum_tether_glide_distance;
	float yaw_sign_correction;
	float set_1_look_forward_offset;
	float set_1_look_up_offset;
	float set_2_look_forward_offset;
	float set_2_look_up_offset;
	float set_0_speed_influence_on_dir;
	float set_1_speed_influence_on_dir;
	float set_2_speed_influence_on_dir;
	float set_0_angular_relaxation;
	float set_1_angular_relaxation;
	float set_2_angular_relaxation;
	float set_0_position_up_offset;
	float set_1_position_up_offset;
	float set_2_position_up_offset;
	float set_0_position_forward_offset;
	float set_1_position_forward_offset;
	float set_2_position_forward_offset;
	float set_0_FOV;
	float set_1_FOV;
	float set_2_FOV;
	float set_0_max_yaw_angle;
	float set_1_max_yaw_angle;
	float set_2_max_yaw_angle;
	int set_1_fade_in_camera_set_change;
	int set_1_fade_out_camera_set_change;
	int set_2_fade_in_camera_set_change;
	int set_2_fade_out_camera_set_change;
	float input_movement_scalar;
	float input_rotation_scalar;
	float input_zoom_scalar;
	float minimum_pitch_desired;
	float maximum_pitch_desired;
	float minimum_zoom;
	float maximum_zoom;
	float horizontal_rotate_tolerance;
	float horizontal_rotate_modifier;
};

class CDCameraTable : public CDTable {
private:
	std::vector<CDCamera> m_entries;
public:
	CDCameraTable();
	~CDCameraTable();
	std::string GetName(void) const override;

std::vector<CDCamera> Query(std::function<bool(CDCamera)> predicate);
	std::vector<CDCamera> GetEntries(void) const;
};