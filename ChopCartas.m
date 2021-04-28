baraja=imread('Baraja_española_completa.png');
figure;imshow(baraja);%208 de ancho, 319 de alto
k=1;
for i=1:319:size(baraja,1)
    for j=1:208:size(baraja,2)
        chop=imcrop(baraja,[j,i,208,319]);
%         figure;
%         imshow(chop);
        %imwrite(chop,'chop.png');
         FileName = sprintf('C:\\Users\\Mario\\OneDrive\\Escritorio\\Uni\\2k20\\Informatica Avanzada\\Cosilla Matlab\\%d.jpg',k);
         imwrite(chop,FileName);
         k=k+1;
    end
end