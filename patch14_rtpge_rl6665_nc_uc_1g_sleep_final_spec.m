%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Revision History
% patch_RL6623:
%    nc_patch for RL6623.20200109:
%    1. np off/dblw on
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% set_phy(1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Parameters (Modify if needed)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
patch_key_addr = '8020';
patch_key = '6500';
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Patch request & wait patch_rdy = 1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
dec2hex(reg_pw('0', 27, 15, 0, 'b820')); % patch request
dec2hex(reg_pw('0', 28, 15, 0, '0010'));

dec2hex(reg_pw('0', 27, 15, 0, 'b830'));
dec2hex(reg_pw('0', 28, 15, 0, '8000'));

dec2hex(reg_pw('0', 27, 15, 0, 'b800'));
patch_rdy = reg_pr('0', 28, 6, 6);
fprintf('... Wait for patch_rdy = 1... ');
while (~patch_rdy)
    patch_rdy = reg_pr('0', 28, 6, 6);
end
fprintf('done\n');
% 
% dec2hex(reg_pw('b82', 16, 4, 4, '1')); % patch request
% patch_rdy = reg_pr('b80', 16, 6, 6);
% fprintf('... Wait for patch_rdy = 1... ');
% while (~patch_rdy)
%     patch_rdy = reg_pr('b80', 16, 6, 6);
% end
% fprintf('done\n');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Set patch_key & patch_lock
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
dec2hex(reg_pw('0', 27, 15, 0, patch_key_addr)); % set patch_key
dec2hex(reg_pw('0', 28, 15, 0, patch_key));

dec2hex(reg_pw('0', 27, 15, 0, 'b82e')); % set patch_lock
dec2hex(reg_pw('0', 28, 15, 0, '0001'));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% UC patch
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
reg_pw('0', 27, 15, 0, '8552');
reg_pw('0', 28, 15, 0, 'af85');
reg_pw('0', 28, 15, 0, '5eaf');
reg_pw('0', 28, 15, 0, '85ee');
reg_pw('0', 28, 15, 0, 'af86');
reg_pw('0', 28, 15, 0, '07af');
reg_pw('0', 28, 15, 0, '8607');
reg_pw('0', 28, 15, 0, 'e0a4');
reg_pw('0', 28, 15, 0, '2ce1');
reg_pw('0', 28, 15, 0, 'a42d');
reg_pw('0', 28, 15, 0, 'f62e');
reg_pw('0', 28, 15, 0, 'e4a4');
reg_pw('0', 28, 15, 0, '2ce5');
reg_pw('0', 28, 15, 0, 'a42d');
reg_pw('0', 28, 15, 0, 'ef13');
reg_pw('0', 28, 15, 0, '3901');
reg_pw('0', 28, 15, 0, '9e09');
reg_pw('0', 28, 15, 0, 'ef13');
reg_pw('0', 28, 15, 0, '3906');
reg_pw('0', 28, 15, 0, '9e39');
reg_pw('0', 28, 15, 0, 'af08');
reg_pw('0', 28, 15, 0, '6102');
reg_pw('0', 28, 15, 0, '8607');
reg_pw('0', 28, 15, 0, 'e0a4');
reg_pw('0', 28, 15, 0, '2ce1');
reg_pw('0', 28, 15, 0, 'a42d');
reg_pw('0', 28, 15, 0, 'f72e');
reg_pw('0', 28, 15, 0, 'e4a4');
reg_pw('0', 28, 15, 0, '2ce5');
reg_pw('0', 28, 15, 0, 'a42d');
reg_pw('0', 28, 15, 0, 'e0a5');  
reg_pw('0', 28, 15, 0, 'cce1');  
reg_pw('0', 28, 15, 0, 'a5cd'); 
reg_pw('0', 28, 15, 0, 'ac2c');
reg_pw('0', 28, 15, 0, '0ce0');
reg_pw('0', 28, 15, 0, 'a46e');
reg_pw('0', 28, 15, 0, 'e1a4');
reg_pw('0', 28, 15, 0, '6f59');
reg_pw('0', 28, 15, 0, '389e');
reg_pw('0', 28, 15, 0, '44ae');
reg_pw('0', 28, 15, 0, 'ebe0');
reg_pw('0', 28, 15, 0, 'a46c');
reg_pw('0', 28, 15, 0, 'e1a4');
reg_pw('0', 28, 15, 0, '6df7');
reg_pw('0', 28, 15, 0, '23e4');
reg_pw('0', 28, 15, 0, 'a46c');
reg_pw('0', 28, 15, 0, 'e5a4');
reg_pw('0', 28, 15, 0, '6dae');
reg_pw('0', 28, 15, 0, '1102'); 
reg_pw('0', 28, 15, 0, '8607');    
reg_pw('0', 28, 15, 0, 'e0a4');
reg_pw('0', 28, 15, 0, '2ce1');
reg_pw('0', 28, 15, 0, 'a42d');
reg_pw('0', 28, 15, 0, 'f72e');
reg_pw('0', 28, 15, 0, 'e4a4');
reg_pw('0', 28, 15, 0, '2ce5');
reg_pw('0', 28, 15, 0, 'a42d');
reg_pw('0', 28, 15, 0, 'eea4');
reg_pw('0', 28, 15, 0, '9420');
reg_pw('0', 28, 15, 0, 'eea4');
reg_pw('0', 28, 15, 0, '9507');
reg_pw('0', 28, 15, 0, 'e0a4');
reg_pw('0', 28, 15, 0, '6ee1');
reg_pw('0', 28, 15, 0, 'a46f');
reg_pw('0', 28, 15, 0, '5938');
reg_pw('0', 28, 15, 0, '9e0f');
reg_pw('0', 28, 15, 0, '3938');
reg_pw('0', 28, 15, 0, '9ff2');
reg_pw('0', 28, 15, 0, 'eed0');
reg_pw('0', 28, 15, 0, '3200');
reg_pw('0', 28, 15, 0, 'eed0');
reg_pw('0', 28, 15, 0, '3304');
reg_pw('0', 28, 15, 0, 'af09');
reg_pw('0', 28, 15, 0, '49ee');
reg_pw('0', 28, 15, 0, 'a494');
reg_pw('0', 28, 15, 0, '20ee');
reg_pw('0', 28, 15, 0, 'a495');
reg_pw('0', 28, 15, 0, 'faaf');
reg_pw('0', 28, 15, 0, '088e');
reg_pw('0', 28, 15, 0, 'eea4');
reg_pw('0', 28, 15, 0, '9420');
reg_pw('0', 28, 15, 0, 'eea4');
reg_pw('0', 28, 15, 0, '95fa');
reg_pw('0', 28, 15, 0, 'e0a4');
reg_pw('0', 28, 15, 0, '2ce1');
reg_pw('0', 28, 15, 0, 'a42d');
reg_pw('0', 28, 15, 0, 'f62e');
reg_pw('0', 28, 15, 0, 'e4a4');
reg_pw('0', 28, 15, 0, '2ce5');
reg_pw('0', 28, 15, 0, 'a42d');
reg_pw('0', 28, 15, 0, 'af09');
reg_pw('0', 28, 15, 0, '37f8');
reg_pw('0', 28, 15, 0, 'f9fa');
reg_pw('0', 28, 15, 0, 'ef69');
reg_pw('0', 28, 15, 0, 'e0a6');
reg_pw('0', 28, 15, 0, '1ee1');
reg_pw('0', 28, 15, 0, 'a61f');
reg_pw('0', 28, 15, 0, '591f');
reg_pw('0', 28, 15, 0, 'ef31');
reg_pw('0', 28, 15, 0, '390f');
reg_pw('0', 28, 15, 0, 'aaf2');
reg_pw('0', 28, 15, 0, 'ef13');
reg_pw('0', 28, 15, 0, '3919');
reg_pw('0', 28, 15, 0, 'abec');
reg_pw('0', 28, 15, 0, 'eea5');
reg_pw('0', 28, 15, 0, 'ce00');
reg_pw('0', 28, 15, 0, 'eea5');
reg_pw('0', 28, 15, 0, 'cf01');
reg_pw('0', 28, 15, 0, 'e0a6');
reg_pw('0', 28, 15, 0, '1ee1');
reg_pw('0', 28, 15, 0, 'a61f');
reg_pw('0', 28, 15, 0, '591f');
reg_pw('0', 28, 15, 0, '390e');
reg_pw('0', 28, 15, 0, '9ff4');
reg_pw('0', 28, 15, 0, 'eea5');
reg_pw('0', 28, 15, 0, 'ce00');
reg_pw('0', 28, 15, 0, 'eea5');
reg_pw('0', 28, 15, 0, 'cf00');
reg_pw('0', 28, 15, 0, 'ef96');
reg_pw('0', 28, 15, 0, 'fefd');
reg_pw('0', 28, 15, 0, 'fc04');
reg_pw('0', 28, 15, 0, '0000');
reg_pw('0', 28, 15, 0, '0000');
reg_pw('0', 27, 15, 0, 'b818');
reg_pw('0', 28, 15, 0, '0857');
reg_pw('0', 27, 15, 0, 'b81a');
reg_pw('0', 28, 15, 0, '0897');
reg_pw('0', 27, 15, 0, 'b81c');
reg_pw('0', 28, 15, 0, '0000');
reg_pw('0', 27, 15, 0, 'b81e');
reg_pw('0', 28, 15, 0, '0000');
reg_pw('0', 27, 15, 0, 'b832');
reg_pw('0', 28, 15, 0, '0003');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NC patch
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
reg_pw('0', 27, 15, 0, 'B820');
reg_pw('0', 28, 15, 0, '0290');
reg_pw('0', 27, 15, 0, 'A012');
reg_pw('0', 28, 15, 0, '0000');
reg_pw('0', 27, 15, 0, 'A014');
reg_pw('0', 28, 15, 0, '2c06');
reg_pw('0', 28, 15, 0, '2c09');
reg_pw('0', 28, 15, 0, '2c39');
reg_pw('0', 28, 15, 0, '2c51');
reg_pw('0', 28, 15, 0, '2c5f');
reg_pw('0', 28, 15, 0, '2c63');
reg_pw('0', 28, 15, 0, '3108');
reg_pw('0', 28, 15, 0, '55fc');
reg_pw('0', 28, 15, 0, '25f7');
reg_pw('0', 28, 15, 0, 'd300');
reg_pw('0', 28, 15, 0, 'a904');
reg_pw('0', 28, 15, 0, 'a908');
reg_pw('0', 28, 15, 0, 'd04c');
reg_pw('0', 28, 15, 0, 'd188');
reg_pw('0', 28, 15, 0, '41ac');
reg_pw('0', 28, 15, 0, 'd079');
reg_pw('0', 28, 15, 0, '4002');
reg_pw('0', 28, 15, 0, 'd191');
reg_pw('0', 28, 15, 0, 'd700');
reg_pw('0', 28, 15, 0, '31df');
reg_pw('0', 28, 15, 0, '7651');
reg_pw('0', 28, 15, 0, 'd701');
reg_pw('0', 28, 15, 0, '6446');
reg_pw('0', 28, 15, 0, '5f79');
reg_pw('0', 28, 15, 0, '6158');
reg_pw('0', 28, 15, 0, '4001');
reg_pw('0', 28, 15, 0, '2c0f');
reg_pw('0', 28, 15, 0, 'd700');
reg_pw('0', 28, 15, 0, '31df');
reg_pw('0', 28, 15, 0, '7651');
reg_pw('0', 28, 15, 0, '6098');
reg_pw('0', 28, 15, 0, 'd701');
reg_pw('0', 28, 15, 0, '4302');
reg_pw('0', 28, 15, 0, '2c1b');
reg_pw('0', 28, 15, 0, 'a101');
reg_pw('0', 28, 15, 0, 'd0ea');
reg_pw('0', 28, 15, 0, 'd182');
reg_pw('0', 28, 15, 0, 'c000');
reg_pw('0', 28, 15, 0, 'c4c0');
reg_pw('0', 28, 15, 0, 'ac80');
reg_pw('0', 28, 15, 0, '16ef');
reg_pw('0', 28, 15, 0, 'a02f');
reg_pw('0', 28, 15, 0, 'a301');
reg_pw('0', 28, 15, 0, 'e027');
reg_pw('0', 28, 15, 0, '0221');
reg_pw('0', 28, 15, 0, '164a');
reg_pw('0', 28, 15, 0, '5ff8');
reg_pw('0', 28, 15, 0, '8107');
reg_pw('0', 28, 15, 0, 'd07a');
reg_pw('0', 28, 15, 0, 'd185');
reg_pw('0', 28, 15, 0, '164a');
reg_pw('0', 28, 15, 0, '5ff8');
reg_pw('0', 28, 15, 0, 'c000');
reg_pw('0', 28, 15, 0, '8267');
reg_pw('0', 28, 15, 0, '8301');
reg_pw('0', 28, 15, 0, '22ae');
reg_pw('0', 28, 15, 0, '22ef');
reg_pw('0', 28, 15, 0, 'e038');
reg_pw('0', 28, 15, 0, '0c08');
reg_pw('0', 28, 15, 0, 'ce04');
reg_pw('0', 28, 15, 0, 'cf02');
reg_pw('0', 28, 15, 0, 'cf01');
reg_pw('0', 28, 15, 0, 'd704');
reg_pw('0', 28, 15, 0, '420b');
reg_pw('0', 28, 15, 0, 'd70c');
reg_pw('0', 28, 15, 0, '5fa6');
reg_pw('0', 28, 15, 0, '1653');
reg_pw('0', 28, 15, 0, 'd0b7');
reg_pw('0', 28, 15, 0, 'd1c3');
reg_pw('0', 28, 15, 0, 'd700');
reg_pw('0', 28, 15, 0, '33f8');
reg_pw('0', 28, 15, 0, '1c85');
reg_pw('0', 28, 15, 0, '63eb');
reg_pw('0', 28, 15, 0, 'd704');
reg_pw('0', 28, 15, 0, '40ab');   
reg_pw('0', 28, 15, 0, '3149'); 
reg_pw('0', 28, 15, 0, '7c4e');
reg_pw('0', 28, 15, 0, '2c45');
reg_pw('0', 28, 15, 0, '5ef9');
reg_pw('0', 28, 15, 0, 'a101');
reg_pw('0', 28, 15, 0, '2c85');
reg_pw('0', 28, 15, 0, 'e038');
reg_pw('0', 28, 15, 0, '0c30');
reg_pw('0', 28, 15, 0, 'ce04');
reg_pw('0', 28, 15, 0, 'cf02');
reg_pw('0', 28, 15, 0, 'cf01');
reg_pw('0', 28, 15, 0, 'd70c');
reg_pw('0', 28, 15, 0, 'd704');
reg_pw('0', 28, 15, 0, '5eeb');
reg_pw('0', 28, 15, 0, 'd70c');
reg_pw('0', 28, 15, 0, '5fa6');
reg_pw('0', 28, 15, 0, '1653');
reg_pw('0', 28, 15, 0, 'd0b7');
reg_pw('0', 28, 15, 0, 'd1c3');
reg_pw('0', 28, 15, 0, '2c67');
reg_pw('0', 28, 15, 0, '6054');
reg_pw('0', 28, 15, 0, 'a701');
reg_pw('0', 28, 15, 0, 'd500');
reg_pw('0', 28, 15, 0, '2108');
reg_pw('0', 28, 15, 0, '4054');
reg_pw('0', 28, 15, 0, '8701');
reg_pw('0', 28, 15, 0, 'a74a');
reg_pw('0', 28, 15, 0, '20de');
reg_pw('0', 28, 15, 0, 'd704');
reg_pw('0', 28, 15, 0, '33f8');
reg_pw('0', 28, 15, 0, '1c85');
reg_pw('0', 28, 15, 0, '605c');
reg_pw('0', 28, 15, 0, '7fab');
reg_pw('0', 28, 15, 0, 'd0bb');
reg_pw('0', 28, 15, 0, 'a101');
reg_pw('0', 28, 15, 0, 'd1b0');
reg_pw('0', 28, 15, 0, 'd002');
reg_pw('0', 28, 15, 0, 'd1c0');
reg_pw('0', 28, 15, 0, 'd704');
reg_pw('0', 28, 15, 0, '317b');
reg_pw('0', 28, 15, 0, '0c7d');
reg_pw('0', 28, 15, 0, '317c');
reg_pw('0', 28, 15, 0, '3c77');
reg_pw('0', 28, 15, 0, '2c72');
reg_pw('0', 28, 15, 0, 'e038');
reg_pw('0', 28, 15, 0, '0c38');
reg_pw('0', 28, 15, 0, 'd705');
reg_pw('0', 28, 15, 0, '4002');
reg_pw('0', 28, 15, 0, '1658');
reg_pw('0', 28, 15, 0, '2872');
reg_pw('0', 28, 15, 0, '8101');
reg_pw('0', 28, 15, 0, 'd07a');
reg_pw('0', 28, 15, 0, 'd1b1');
reg_pw('0', 28, 15, 0, 'd704');
reg_pw('0', 28, 15, 0, '33fb');
reg_pw('0', 28, 15, 0, '1c85');
reg_pw('0', 28, 15, 0, '5e8b');
reg_pw('0', 28, 15, 0, '2c81');
reg_pw('0', 28, 15, 0, '8c38');
reg_pw('0', 28, 15, 0, 'd503');
reg_pw('0', 28, 15, 0, 'a304');
reg_pw('0', 28, 15, 0, 'a260');
reg_pw('0', 28, 15, 0, 'd500');
reg_pw('0', 28, 15, 0, 'd705');
reg_pw('0', 28, 15, 0, '4002');
reg_pw('0', 28, 15, 0, '1658');
reg_pw('0', 28, 15, 0, '2886');
reg_pw('0', 27, 15, 0, 'A01A');
reg_pw('0', 28, 15, 0, '0000');
reg_pw('0', 27, 15, 0, 'A00A');
reg_pw('0', 28, 15, 0, '00dd');
reg_pw('0', 27, 15, 0, 'A008');
reg_pw('0', 28, 15, 0, '0107');
reg_pw('0', 27, 15, 0, 'A006');
reg_pw('0', 28, 15, 0, '0849');
reg_pw('0', 27, 15, 0, 'A004');
reg_pw('0', 28, 15, 0, '081b');
reg_pw('0', 27, 15, 0, 'A002');
reg_pw('0', 28, 15, 0, '32ee');
reg_pw('0', 27, 15, 0, 'A000');
reg_pw('0', 28, 15, 0, 'f5fa');
reg_pw('0', 27, 15, 0, 'B820');
reg_pw('0', 28, 15, 0, '0210');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Clear patch_key & patch_lock
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
dec2hex(reg_pw('0', 27, 15, 0, 'b82e'));
dec2hex(reg_pw('0', 28, 15, 0, '0000'));

dec2hex(reg_pw('0', 27, 15, 0, patch_key_addr)); % clear patch_key
dec2hex(reg_pw('0', 28, 15, 0, '0000'));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Release patch request & wait patch_rls = 0
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
dec2hex(reg_pw('0', 27, 15, 0, 'b820')); % release patch request
dec2hex(reg_pw('0', 28, 15, 0, '0000'));

dec2hex(reg_pw('0', 27, 15, 0, 'b800')); % check patch release
patch_rls = reg_pr('0', 28, 6, 6);
fprintf('... Wait for patch_rls = 0... ');
while patch_rls~=0
    patch_rls = reg_pr('0', 28, 6, 6);
end
fprintf('done\n');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
