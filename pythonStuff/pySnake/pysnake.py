import os,sys
import pygame
from pygame.locals import *
"""from Helpers import * """ 


if not pygame.font : print "warning, not font"
if not pygame.mixer: print 'warning, not mixer'


def load_image(name,colorkey=None):
    fullname = os.path.join('data',name)
    try:
	image = pygame.image.load(fullname)
    except pygame.error,message:
	print 'cannot load image:',name
	raise SystemExit, message
    image = image.convert()
    if colorkey is not None:
	if colorkey is -1:
	    colorkey = image.get_at((0,0))
	image.set_colorkey(colorkey,RLEACCEL)
    return image,image.get_rect()
    

class PySnakeMain(object):
    """The main pyman class- this class handles the main initialization and
    creating of the Game.
    """
    
    def __init__(self,width = 640,height = 480  ):
        """Initialize"""
        """Initial Pygame"""
        pygame.init()
        """set the window size"""
        self.width = width
        self.height = height
        """create the screen"""
        self.screen = pygame.display.set_mode((self.width,self.height))
        
    def MainLoop(self):
        self.loadSprites()
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()
            self.snake_sprites.draw(self.screen)
            pygame.display.flip()
            
    def loadSprites(self):
        self.snake = Snake()
        self.snake_sprites = pygame.sprite.RenderPlain((self.snake))
        
        
                        
                    
class Snake(pygame.sprite.Sprite):
    """This is our snake that will move around the screen
    """
    
    def __init__(self ):
        pygame.sprite.Sprite.__init__(self)
        self.image,self.rect = load_image('snake.png',-1)
        self.pellets = 0

        
        
        

                    
if __name__ == '__main__':
    mainWindow = PySnakeMain()
    mainWindow.MainLoop()
    

        
        
        
        
	
