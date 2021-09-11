 project(
	'ChessSDL',
	'cpp',
	default_options : ['cpp_std=c++20', 'warning_level=3',
							 'optimization=2','debug=false',
							 'werror=false', 'b_sanitize=none'],
	version : '1.0'

)

include_dir = include_directories('include')

src_files = ['src/main.cpp', 'src/Game.cpp',  'src/Texture.cpp',
				 'src/InputHandler.cpp', 'src/Vector2D.cpp', 'src/tinyxml2.cpp',
				 'src/LoaderParams.cpp',
				 'src/MenuButton.cpp', 'src/Level.cpp',
				 'src/LevelParser.cpp', 'src/TileLayer.cpp',
				 'src/ObjectLayer.cpp',  'src/GameObjectFactory.cpp']

game_objects = ['src/SDLGameObject.cpp', 'src/Player.cpp', 'src/Enemy.cpp', 'src/AnimatedGraphic.cpp']

game_states = ['src/GameStateMachine.cpp', 'src/GameOverState.cpp', 'src/PlayState.cpp',
					'src/PauseState.cpp', 'src/StateParser.cpp', 'src/MainMenuState.cpp',
					'src/SelectPlayerState.cpp']




sdl2_dep = dependency('SDL2')
sdl2_image_dep = dependency('SDL2_image')

executable('main',
			  sources : [src_files, game_states, game_objects],
			  include_directories: include_dir,
			  dependencies : [sdl2_dep, sdl2_image_dep])
